#include "../../include/32/ld32.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/elf32_common.h"
#include "../../include/constvar.h"

extern  int  nFiles;
extern  _Bool DisplayHeader;
extern  _Bool DisplaySection;
extern  _Bool DisplaySymTab;

static error_t
Elf32_InitELF32Headers(void)
{
	Elf32_Headers.Elems = nFiles;
	Elf32_Headers.ELFHeader = (Elf32_Ehdr *)malloc(sizeof(Elf32_Ehdr) * nFiles);
	if(Elf32_Headers.ELFHeader == NULL)
		return (-1);
	else
		return (0);
}

static error_t
Elf32_InitSections(Elf32_Word Entry,FILE *ObjectFile)
{
	static _Bool Inited = 0;
	if(!Inited)  {
		Elf32_SectionBase = (struct Elf32_Shdrs *)malloc(sizeof(Elf32_Shdr) * nFiles);
		Inited = 1;
	}

	Elf32_Word OffsetOfSection = ELF32_EHDR_HDR_ATTR(Entry,e_shoff);
	Elf32_Word Size = ELF32_EHDR_HDR_ATTR(Entry,e_shnum) * sizeof(Elf32_Shdr);
	ELF32_SHDR_ELEMS(Entry) = ELF32_EHDR_HDR_ATTR(Entry,e_shnum);
	ELF32_SHDR_SECTIONS(Entry) = (Elf32_Shdr *)malloc(Size);

	fseek(ObjectFile,OffsetOfSection,SEEK_SET);
	fread(ELF32_SHDR_SECTIONS(Entry),Size,1,ObjectFile);
	return (0);
}

static char *
Elf32_Type(Elf32_Word Type)
{
	Elf32_Word Index;

	if(Type == 0xfe00)
		Index = 5;
	else if(Type == 0xfeff)
		Index = 6;
	else if(Type == 0xff00)
		Index = 7;
	else if(Type == 0xffff)
		Index = 8;
	else 
		Index = Type;
	return (FileTypes[Index]);
}


static char *
Elf32_Machine(Elf32_Word Machine){
	Elf32_Word Index;

	if(Machine == 183)
		Index = 112;
	else if(Machine == 243)
		Index = 113;
	else
		Index = Machine;

	return (MachineTypes[Index]);
}

static void
Elf32_DisplayHeader(Elf32_Word Entry)
{
	Elf32_Ehdr *Ehdr = ELF32_EHDR_HEADER(Entry);
	char *Magic = Ehdr->e_ident;
	printf("Magic:	");
	for(int Index = 0;Index < 16;Index++,Magic += 1) {
		printf("%02x ",*Magic);
	}
	printf("\n");

	printf("ELF type: 			0x%08x %s\n",Ehdr->e_type,Elf32_Type(Ehdr->e_type));
	printf("Machine:  			0x%08x (%s)\n",Ehdr->e_machine,Elf32_Machine(Ehdr->e_machine));
	printf("Version:  			0x%08x\n",Ehdr->e_version);
	printf("Entry Point: 			0x%08x\n",Ehdr->e_entry);
	printf("Program offset: 		0x%08x (bytes into file)\n",Ehdr->e_phoff);
	printf("Sections offset: 		0x%08x (bytes into file)\n",Ehdr->e_shoff);
	printf("Flags:	  			0x%08x\n",Ehdr->e_flags);
	printf("Header Size: 			0x%08x (bytes)\n",Ehdr->e_ehsize);
	printf("Program Header's Size: 		0x%08x (bytes)\n",Ehdr->e_phentsize);
	printf("Number of Program Header: 	0x%08x\n",Ehdr->e_phnum);
	printf("Size of Section: 		0x%08x (bytes)\n",Ehdr->e_shentsize);
	printf("Number of section headers: 	0x%08x\n",Ehdr->e_shnum);
	printf("String table Index: 		0x%08x\n",Ehdr->e_shstrndx);
}

#define DisplayFormatTitle(flags)		do{\
						printf("[Nr] Name%16cType%16cAddr%10cOff%10cSize	ES Flg Lk Inf Al\n",' ',' ',' ',' ');\
						}while(0);


static error_t
Elf32_DisplaySections(Elf32_Word nFile,FILE *ObjectFile)
{
	Elf32_Off Entry = 0;
	Elf32_Off SectionsStringSectionIndex = ELF32_EHDR_HDR_ATTR(nFile,e_shstrndx);
	Elf32_Word SectionsNumber = ELF32_EHDR_HDR_ATTR(nFile,e_shnum);

	Elf32_Shdr *SectionsStringSection = ELF32_SHDR_SECTION(nFile,SectionsStringSectionIndex);
	Elf32_Shdr *ShdrIter = ELF32_SHDR_SECTIONS(nFile);

	char *SectionsName = (char *)malloc(sizeof(char) * SectionsStringSection->sh_size);

	fseek(ObjectFile,SectionsStringSection->sh_offset,SEEK_SET);
	fread(SectionsName,sizeof(char),SectionsStringSection->sh_size,ObjectFile);

	DisplayFormatTitle(NULL);

	for(;Entry < SectionsNumber;Entry++,ShdrIter += 1) {
		if(Entry >= 10)
			printf("[%d] ",Entry);
		else
			printf("[ %d] ",Entry);
		printf("%s",SectionsName + ShdrIter->sh_name);
		DisplayFormatSectionInfo(ShdrIter,SectionsName + ShdrIter->sh_name);
	}
	printf("\n");
	free(SectionsName);
}

static void
Elf32_InitSymTab(Elf32_Word nFile,FILE *ObjectFile)
{
	static _Bool Inited = 0;
	Elf32_Shdr *Shdr = ELF32_SHDR_SECTIONS(nFile);
	Elf32_Word OffsetOfSymTab;
	Elf32_Word SizeOfSymTab;
	Elf32_Word Elems = ELF32_SHDR_ELEMS(nFile);	
	if(!Inited) {
		Elf32_SymTabBase = (struct Elf32_Syms *)malloc(sizeof(struct Elf32_Syms) * nFiles);
		Inited = 1;
	}
	for(int Entry = 0;Entry < Elems;Entry++,Shdr += 1) {
		if(Shdr->sh_type == SHT_SYMTAB) {
			OffsetOfSymTab = Shdr->sh_offset;
			SizeOfSymTab = Shdr->sh_size;
			ELF32_SYM_ELEMS(nFile) = Shdr->sh_size / Shdr->sh_entsize;
			ELF32_SYM_TABS(nFile) = (Elf32_Sym *)malloc(SizeOfSymTab);
			fseek(ObjectFile,OffsetOfSymTab,SEEK_SET);
			fread(ELF32_SYM_TABS(nFile),SizeOfSymTab,1,ObjectFile);
			return ;
		}
	}
}

static Elf32_Off
Elf32_sortSectionsIndexByName(char *SectionName,Elf32_Off nFile,FILE *ObjectFile)
{
	Elf32_Shdr *ShdrIter;
	Elf32_Word Elems = ELF32_SHDR_ELEMS(nFile);
	Elf32_Off Offset = ELF32_EHDR_HDR_ATTR(nFile,e_shstrndx);

	ShdrIter = ELF32_SHDR_SECTION(nFile,Offset);
	char *StringBuffer = (char *)malloc(ELF32_SHDR_SECTION_ATTR(nFile,Offset,sh_size));
	Elf32_Off OffsetSectionsStringSection = ELF32_SHDR_SECTION_ATTR(nFile,Offset,sh_offset);

	fseek(ObjectFile,OffsetSectionsStringSection,SEEK_SET);
	fread(StringBuffer,ShdrIter->sh_size,1,ObjectFile);

	ShdrIter = ELF32_SHDR_SECTIONS(nFile); 

	Elf32_Word Entry = 0;
	for(;Entry < Elems;Entry++,ShdrIter += 1) {
		if(strcmp(SectionName,StringBuffer + ShdrIter->sh_name) == 0) {
			free(StringBuffer);
			return Entry;
		}
	}
	free(StringBuffer);
	return (Entry);
}

#define FormatDisplaySymbolTitle(flags)			do{\
							printf(" Num:	Value		Size  Type	Vis	 Ndx 	Name\n");\
							}while(0);



static const char *
Elf32_SymbolTableBind(unsigned char SymbolTableInfo)
{
	int Mask = 0xf0;
	return (SymbolTableBind[(Mask & SymbolTableInfo)]);
}

static const char *
Elf32_SymbolTableType(unsigned char SymbolTableInfo)
{
	int Mask = 0x0f;
	return (SymbolTableType[(Mask & SymbolTableInfo)]);
}

static void
Elf32_DisplaySymTab(Elf32_Word Entry,FILE *ObjectFile)
{
	Elf32_Off Index = Elf32_sortSectionsIndexByName(".strtab",Entry,ObjectFile);
	
	Elf32_Shdr *Shdr = ELF32_SHDR_SECTIONS(Entry);
	Elf32_Word Elems = ELF32_SYM_ELEMS(Entry);

	char *StringTab = (char *)malloc(sizeof(char) * ELF32_SHDR_SECTION_ATTR(Entry,Index,sh_size));
	
	fseek(ObjectFile,ELF32_SHDR_SECTION_ATTR(Entry,Index,sh_offset),SEEK_SET);
	fread(StringTab,ELF32_SHDR_SECTION_ATTR(Entry,Index,sh_size),1,ObjectFile);

	Elf32_Word Length;

	FormatDisplaySymbolTitle(NULL);
	for(Elf32_Word Index = 0;Index < Elems;Index++) {
		printf("%4d: ",Index);
		printf("%016x",ELF32_SYM_TAB_ATTR(Entry,Index,st_value));
		printf("%6d",ELF32_SYM_TAB_ATTR(Entry,Index,st_size));
		printf("  %s",Elf32_SymbolTableType(ELF32_SYM_TAB_ATTR(Entry,Index,st_info)));
		Length = strlen(Elf32_SymbolTableType(ELF32_SYM_TAB_ATTR(Entry,Index,st_info)));
		Length = 10 - Length;
		while(Length--)	printf("%c",' ');
		printf("%s","DEFAULT");
		printf("\t%4x",ELF32_SYM_TAB_ATTR(Entry,Index,st_shndx));
		printf("\t%s\n",StringTab + ELF32_SYM_TAB_ATTR(Entry,Index,st_name));
	}
	free(StringTab);
}

error_t
Elf32_ReadELFHeader(const char *FileName[])
{
	Elf32_InitELF32Headers();

	FILE *ObjectFile;
	
	for(Elf32_Word nFile;nFile < nFiles;nFile++) {
		ObjectFile = fopen(FileName[nFile + 1],"r");
		if(ObjectFile == NULL) {
			printf("No Such File: %s\n",FileName[nFile + 1]);
			exit(-1);
		}
		
		fread(ELF32_EHDR_HEADER(nFile),sizeof(Elf32_Ehdr),1,ObjectFile);
		if(DisplayHeader) {
			printf("File Name: %s\n",FileName[nFile + 1]);
			Elf32_DisplayHeader(nFile);
			printf("\n");
		}

		Elf32_InitSections(nFile,ObjectFile);
		
		if(DisplaySection) {
			Elf32_DisplaySections(nFile,ObjectFile);
			printf("\n");
		}

		Elf32_InitSymTab(nFile,ObjectFile);

		if(DisplaySymTab) {
			Elf32_DisplaySymTab(nFile,ObjectFile);
			printf("\n");
		}

		fclose(ObjectFile);
	}
	return (0);
}


void
PrintNSpace(Elf32_Word Spaces)
{
	if(Spaces <0)
		Spaces = 1;

	while(Spaces--)
		printf("%c",' ');
}

Elf32_Word
PrintFlags(Elf32_Word flags)
{
	char *Flags = (char *)malloc(sizeof(char) * MAX_SECTION_FLAGS + 1);
	short Index = 0;

	if(flags & SHF_WRITE)
		Flags[Index++] = 'W';
	if(flags & SHF_ALLOC)
		Flags[Index++] = 'A';
	if(flags & SHF_EXECINSTR)
		Flags[Index++] = 'E';
	if(flags & SHF_MERGE)
		Flags[Index++] = 'M';
	if(flags & SHF_STRINGS)
		Flags[Index++] = 'S';
	if(flags & SHF_INFO_LINK)
		Flags[Index++] = 'I';
	if(flags & SHF_LINK_ORDER)
		Flags[Index++] = 'L';
	if(flags & SHF_OS_NONCONFORMING)
		Flags[Index++] = 'O';
	if(flags & SHF_GROUP)
		Flags[Index++] = 'G';
	if(flags & SHF_TLS)
		Flags[Index++] = 'T';
	if(flags & SHF_COMPRESSED)
		Flags[Index++] = 'C';
	if(flags & SHF_MASKOS)
		Flags[Index++] = 'K';
	if(flags & SHF_MASKPROC)
		Flags[Index++] = 'P';
	Flags[Index] = '\0';
	printf("%s",Flags);
	return (Index);
}


void
DisplayFormatSectionInfo(Elf32_Shdr *Shdr,char *SourceString)
{

	Elf32_Word StringLength = strlen(SourceString);

	PrintNSpace(20 - StringLength);
	printf("%s",SectionType[Shdr->sh_type]);

	StringLength = strlen(SectionType[Shdr->sh_type]);
	PrintNSpace(20 - StringLength);
	printf("%08x",Shdr->sh_addr);

	StringLength = 8;
	PrintNSpace(14 - StringLength);
	printf("%06x",Shdr->sh_offset);

	StringLength = 6;
	PrintNSpace(13 - StringLength);
	printf("%06x",Shdr->sh_size);

	StringLength = 6;
	PrintNSpace(8 - StringLength);
	printf("%02x",Shdr->sh_entsize);

	printf(" ");
	StringLength = PrintFlags(Shdr->sh_flags);

	PrintNSpace(4 - StringLength);
	printf("%2d",Shdr->sh_link);

	PrintNSpace(3);
	printf("%d",Shdr->sh_info);

	StringLength = Shdr->sh_info > 10 ? 2 : 1;
	PrintNSpace(3 - StringLength);
	printf("%-d\n",Shdr->sh_addralign);

}

