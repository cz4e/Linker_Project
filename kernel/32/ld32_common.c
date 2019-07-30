#include <sys/types.h>
#include <sys/elf32.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/constvar.h"

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
