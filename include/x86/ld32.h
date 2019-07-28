#include <sys/types.h>
#include <sys/elf32.h>
#include <stdio.h>


typedef long error_t;

Elf32_Ehdr	*Elf32_Ehdrs = NULL;			/* Two demensions array */
Elf32_Shdr	*Elf32_Shdrs = NULL;			/* Two demensions array */
Elf32_Sym	*Elf32_Syms = NULL;			/* Two demensions array */
Elf32_Shdr	*Elf32_SectionStirngTable = NULL; /* Two demensions array*/

error_t
Elf32_ReadELF(char *FileName[]);			/* Analysis ELF32 format	*/

error_t
Elf32_getELFHeader(Elf32_Ehdr *Ehdr,FILE *ObjectFile);			/* Read ELF32 Header		*/

Elf32_Shdr *
Elf32_getELFSectionTable(Elf32_Ehdr *Ehdr,Elf32_Off nFile,FILE *ObjectFile);

Elf32_Shdr *
Elf32_getSectionsStringSection(Elf32_Shdr *Shdr,Elf32_Off SectionsStringSectionIndex,Elf32_Off nFile);


