#ifndef _LD_32_
#define _LD_32_
#endif

#include "../../include/x86/ld32.h"
#include "../../include/include/constvar.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern _Bool DisplayELFHeader;
extern long  nFiles;
extern _Bool DisplayELFSections;

int 	space = 0;

#define MAX_SECTION_TYPES	12
char *SectionType[MAX_SECTION_TYPES] = {
					"NULL",
					"PROGBITS",
					"SYMTAB",
					"STRTAB",
					"RELA",
					"HASH",
					"DYNAMIC",
					"NOTE",
					"NOBITS",
					"REL",
					"SHLIB",
					"DNYSYM"
					};

#define FormatDisplaySectionHeadersTitle(flag)		do{\
							printf("[Nr] Name		Type		Addr	Off	Size	ES Flg Lk Inf Al\n");\
							}while(0);

#define FormatDisplaySectionHeadersInfo(Shdr)		do{\
								space = 20 - space;\
								while(space--)\
									printf("%c",' ');\
								printf("%+s",SectionType[Shdr->sh_type]);\
								printf("\t%08x",Shdr->sh_addr);\
								printf("\t%06x",Shdr->sh_offset);\
								printf("\t%06x",Shdr->sh_size);\
								printf("\t%02x",Shdr->sh_entsize);\
								printf(" %s",Elf32_SectionFlags(Shdr->sh_flags));\
								printf(" %x",Shdr->sh_link);\
								printf(" %x",Shdr->sh_info);\
								printf(" %x\n",Shdr->sh_addralign);\
							}while(0);

#define MAX_SECTION_FLAGS	13
char *Flags = NULL;

static char *
Elf32_SectionFlags(Elf32_Word flags)
{
	if(!Flags)
		Flags = (char *)malloc(sizeof(char) * MAX_SECTION_FLAGS + 1);
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
	return (Flags);
}

error_t
Elf32_getELFHeader(Elf32_Ehdr *Ehdr,FILE *ObjectFile)
{
	fread(Ehdr,sizeof(Elf32_Ehdr),1,ObjectFile);
	return (0);
}

static char *FileTypes[ET_NUMBER] = {
		"NONE (Unknown type)",
		"REL (Relocatable)",
		"Exec (Executable)",
		"Shared (Shared object)",
		"Core (Core File)",
		"FOSS (First Operating system specific)",
		"LOSS (Last Operating system sepeicfic)",
		"FPS (First Processor-Specific)",
		"LPS (Last Processor-Specific)"
		};

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

static char *MachineTypes[EM_NUMBER + 1] = {
			"Unknown machine",
			"AT&T WE32100",
			"Sun SPARC",
			"Intel i386",
			"Motorola 68000",
			"Motorola 88000 ",
			"Intel MCU",
			"Intel i860. ",
			"MIPS R3000 Big-Endian only. ",
			"IBM System/370. ",
			"MIPS R3000 Little-Endian. ",
			"HP PA-RISC. ",
			"Fujitsu VPP500. ",
			"SPARC v8plus. ",
			"Intel 80960. ",
			"PowerPC 32-bit. ",
			"PowerPC 64-bit. ",
			"IBM System/390. ",
			"NEC V800. ",
			"Fujitsu FR20. ",
			"TRW RH-32. ",
			"Motorola RCE. ",
			"ARM. ",
			"Hitachi SH. ",
			"SPARC v9 64-bit. ",
			"Siemens TriCore embedded processor. ",
			"Argonaut RISC Core. ",
			"Hitachi H8/300",
			"Hitachi H8/300H. ",
			"Hitachi H8S.",
			"Hitachi H8/500. ",
			"Intel IA-64 Processor. ",
			"Stanford MIPS-X. ",
			"Motorola ColdFire. ",
			"Motorola M68HC12. ",
			"Fujitsu MMA. ",
			"Siemens PCP. ",
			"Sony nCPU. ",
			"Denso NDR1 microprocessor. ",
			"Motorola Star*Core processor. ",
			"Toyota ME16 processor",
			"STMicroelectronics ST100 processor. ",
			"Advanced Logic Corp. TinyJ processor. ",
			"Advanced Micro Devices x86-64 ",
			"Advanced Micro Devices x86-64 (compat) ",
			"Sony DSP Processor. ",
			"Siemens FX66 microcontroller. ",
			"STMicroelectronics ST9+ 8/16 microcontroller. ",
			"STmicroelectronics ST7 8-bit microcontroller. ",
			"Motorola MC68HC16 microcontroller. ",
			"Motorola MC68HC11 microcontroller. ",
			"Motorola MC68HC08 microcontroller. ",
			"Motorola MC68HC05 microcontroller. ",
			"Silicon Graphics SVx. ",
			"STMicroelectronics ST19 8-bit mc. ",
			"Digital VAX. ",
			"Axis Communications 32-bit embedded processor. ",
			"Infineon Technologies 32-bit embedded processor. ",
			"Element 14 64-bit DSP Processor. ",
			"LSI Logic 16-bit DSP Processor. ",
			"Donald Knuth's educational 64-bit proc. ",
			"Harvard University machine-independent object files.",
			"SiTera Prism. ",
			"Atmel AVR 8-bit microcontroller. ",
			"Fujitsu FR30. ",
			"Mitsubishi D10V. ",
			"Mitsubishi D30V. ",
			"NEC v850. ",
			"Mitsubishi M32R. ",
			"Matsushita MN10300. ",
			"Matsushita MN10200. ",
			"picoJava. ",
			"OpenRISC 32-bit embedded processor. ",
			"ARC Cores Tangent-A5. ",
			"Tensilica Xtensa Architecture. ",
			"Alphamosaic VideoCore processor. ",
			"Thompson Multimedia General Purpose Processor. ",
			"National Semiconductor 32000 series. ",
			"Tenor Network TPC processor. ",
			"Trebia SNP 1000 processor. ",
			"STMicroelectronics ST200 microcontroller. ",
			"Ubicom IP2xxx microcontroller family. ",
			"MAX Processor. ",
			"National Semiconductor CompactRISC microprocessor. ",
			"Fujitsu F2MC16. ",
			"Texas Instruments embedded microcontroller msp430. ",
			"Analog Devices Blackfin (DSP) processor. ",
			"S1C33 Family of Seiko Epson processors. ",
			"Sharp embedded microprocessor. ",
			"Arca RISC Microprocessor. ",
			"Microprocessor series from PKU-Unity Ltd.  ",
			"AArch64 (64-bit ARM) ",
			"RISC-V ",
		};
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
Elf32_DisplayELFHeader(Elf32_Ehdr *Ehdr)
{
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

Elf32_Shdr *
Elf32_getELFSectionTable(Elf32_Ehdr *Ehdr,Elf32_Off nFile,FILE *ObjectFile)
{
	Elf32_Off Offset = Ehdr->e_shoff;
	Elf32_Half Size = Ehdr->e_shentsize;
	Elf32_Half NumberOfSections = Ehdr->e_shnum;
	Elf32_Shdr *ShdrIter = Elf32_Shdrs + nFile * Size;

	fseek(ObjectFile,Offset,SEEK_SET);
	fread(ShdrIter,Size,NumberOfSections,ObjectFile);

	return (ShdrIter);
}

Elf32_Shdr *
Elf32_getSectionsStringSection(Elf32_Shdr *Sdhr, Elf32_Off SectionsStringSectionIndex,Elf32_Off nFile)
{	
	Elf32_Shdr	*SectionsStringSection = Sdhr  + SectionsStringSectionIndex;
	return (SectionsStringSection);
}

static void
Elf32_DisplaySectionName(Elf32_Off OffsetOfSecStrTable,Elf32_Off OffsetOfSectionName,FILE *ObjectFile)
{
	char ch;

	fseek(ObjectFile,OffsetOfSecStrTable + OffsetOfSectionName,SEEK_SET);
	while((ch = fgetc(ObjectFile)) != '\0') {
		printf("%c",ch);
		space++;
	}
}

static void
Elf32_DisplayELFSections(Elf32_Shdr *Shdr,Elf32_Ehdr *Ehdr,Elf32_Off nFile,FILE *ObjectFile)
{
	Elf32_Half NumberOfSections = Ehdr->e_shnum;
	Elf32_Off IndexOfSecStrTable = Ehdr->e_shstrndx;
	Elf32_Off OffsetOfSectionName;
	Elf32_Shdr *ShdrIter = Shdr;

	Elf32_Shdr *SectionsStringSection = Elf32_getSectionsStringSection(ShdrIter,IndexOfSecStrTable,nFile);
	Elf32_Off OffsetOfSecStrTable = SectionsStringSection->sh_offset;
	Elf32_Off nSection = 0;

	FormatDisplaySectionHeadersTitle(NULL);
	for(;nSection < NumberOfSections;nSection++,ShdrIter += 1) {
		OffsetOfSectionName = ShdrIter->sh_name;

		if(nSection >= 10) {
			printf("[%d] ",nSection);
		} else {
			printf("[ %d] ",nSection);
		}

		Elf32_DisplaySectionName(OffsetOfSecStrTable,OffsetOfSectionName,ObjectFile);
		
		FormatDisplaySectionHeadersInfo(ShdrIter);
	}
}

error_t
Elf32_ReadELF(char *FileName[])
{
	int ErrorCode = 0;
	FILE *ObjectFile = NULL;

	int nFile = 1;

	Elf32_Ehdrs = (Elf32_Ehdr *)malloc(sizeof(Elf32_Ehdr) * nFiles);
	Elf32_Ehdr *EhdrIter = Elf32_Ehdrs;

	Elf32_Shdr *ShdrIter = NULL;

	_Bool AlreadyAlloced = (_Bool) 0;

	for(;nFile <= nFiles;nFile++,EhdrIter += 1) {
		ObjectFile = fopen(FileName[nFile],"r");
	
		if(ObjectFile == NULL) {
			printf("No Such File: %s\n",FileName[nFile]);
			ErrorCode = -1;
			exit(ErrorCode);
		}

		Elf32_getELFHeader(EhdrIter,ObjectFile);

		if(DisplayELFHeader) {
			printf("File Name: %s\n",FileName[nFile]);
			Elf32_DisplayELFHeader(EhdrIter);
			printf("\n");
		}
		
		if(!AlreadyAlloced) {
			AlreadyAlloced = (_Bool)1;
			Elf32_Shdrs = (Elf32_Shdr *)malloc(EhdrIter->e_shentsize * EhdrIter->e_shnum * nFile);
			ShdrIter = Elf32_Shdrs;
		}

		ShdrIter = Elf32_getELFSectionTable(EhdrIter,nFile,ObjectFile);
		
		if(DisplayELFSections) {
			printf("Section of ELF: \n");
			Elf32_DisplayELFSections(ShdrIter,EhdrIter,nFile,ObjectFile);
		}
		fclose(ObjectFile);
	}
}
