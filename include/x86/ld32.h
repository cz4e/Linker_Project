#include <sys/types.h>
#include <sys/elf32.h>
#include <stdio.h>


typedef long error_t;

struct ELFHeader {
	Elf32_Ehdr	*Elf32_Ehdrs;
	Elf32_Word	Elems;
};

struct ELFHeader Elf32_Ehdrs;


struct SectionsHeaderEachFile {
	Elf32_Shdr	*SectionsHeader;
	Elf32_Word	Elems;
};

struct SectionsHeader {
	struct SectionsHeaderEachFile  *Elf32_Shdrs;
	Elf32_Word	Elems;
};

struct SectionsHeader *Elf32_Shdrs;


struct SymbolTableEachFile {
	Elf32_Sym	*SymbolTable;
	Elf32_Word	Elems;
};

struct SymbolTables {
	struct SymbolTableEachFile	*Elf32_Syms;
	Elf32_Word	Elems;
};

struct SymbolTables *Elf32_Syms;




error_t
Elf32_ReadELFHeader(char *FileName[]);			/* Analysis ELF32 format	*/

error_t
Elf32_getELFHeader(Elf32_Ehdr *Ehdr,FILE *ObjectFile);			/* Read ELF32 Header		*/

Elf32_Shdr *
Elf32_getELFSectionTable(Elf32_Ehdr *Ehdr,Elf32_Off nFile,FILE *ObjectFile);

Elf32_Shdr *
Elf32_getSectionsStringSection(Elf32_Shdr *Shdr,Elf32_Off SectionsStringSectionIndex,Elf32_Off nFile);


