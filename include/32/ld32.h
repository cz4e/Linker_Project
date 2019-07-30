#ifndef _LD_32_H_
#define _LD_32_H_
#endif

#include <sys/types.h>
#include <sys/elf32.h>
#include <stdio.h>

struct Elf32_Ehdrs {
	int  	Elems;
	Elf32_Ehdr  	*ELFHeader;
};

struct Elf32_Shdrs {
	int 	Elems;
	Elf32_Shdr	*Sections;
};

struct Elf32_Syms {
	int	Elems;
	Elf32_Sym	*SymTab;
};

struct Elf32_Ehdrs	Elf32_Headers;

struct Elf32_Shdrs	*Elf32_SectionBase;

struct Elf32_Syms	*Elf32_SymTabBase;


typedef long	error_t;
