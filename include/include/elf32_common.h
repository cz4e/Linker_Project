

#define PFILE_EHDR(entry)		(Elf32_Ehdrs.Elf32_Ehdrs + entry)		/* Elf32_Ehdrs.Elf32_Ehdrs + entry 			*/
#define PFILE_EHDR_P(entry)		(&(PFILE_EHDR(entry)))				/* &(Elf32_Ehdrs.Elf32_Ehdrs + entry)			*/
#define PFILE_EHDR_ELEMS(entry)		(Elf32_Ehdrs.Elems)				/* Elf32_Ehdrs.Elems					*/
#define PFILE_EHDR_ATTRIBUTE(entry,attr) \
					(PFILE_EHDR(entry)->attr)			/* (Elf32_Ehdrs.Elf32_Ehdrs + entry)->attr		*/

#define PFILE_SHDR(entry)		(Elf32_Shdrs + entry)				/* Elf32_Shdrs + entry					*/
#define PFILE_SHDR_ELEMS(entry)		(Elf32_Shdrs->Elems)				/* Elf32_Shdrs->Elems					*/
#define PFILE_SHDR_P(entry)		(&(PFILE_SHDR(entry)))				/* &(Elf32_Shdrs + entry)				*/

#define PFILE_SHDR_SHDRS(entry)		(PFILE_SHDR(entry)->Elf32_Shdrs)		/* (Elf32_Shdrs + entry)->Elf32_Shdrs			*/
#define PFILE_SHDR_SHDRS_ELEMS(entry)	(PFILE_SHDR(entry)->Elems)			/* (Elf32_Shdrs + entry)->Elems				*/
#define PFILE_SHDR_SHDRS_P(entry)	(&(PFILE_SHDR_SHDRS(entry)))			/* &(Elf32_Shdrs + entry)				*/

#define PFILE_SHDR_HEADERS(entry)	(PFILE_SHDR_SHDRS(entry)->SectionsHeader)	/* (Elf32_Shdrs + entry)->Elf32_Shdrs->SectionsHeader	*/
#define PFILE_SHDR_HEADERS_P(entry)	(&(PFILE_SHDR_HEADERS(entry)))			/* &((Elf32_Shdrs + entry)->Elf32_Shdrs->SectionsHeader)*/

#define PFILE_SYM(entry)		(Elf32_Syms + entry)				/* Elf32_Syms + entry					*/
#define PFILE_SYM_P(entry)		(&(PFILE_SYM(entry)))				/* &(Elf32_Syms + entry)				*/
#define PFILE_SYM_ELEMS(entry)		(PFILE_SYM(entry)->Elems)			/* (Elf32_Sym + entry)->Elems				*/

#define PFILE_SYM_SYMS(entry)		(PFILE_SYM(entry)->Elf32_Syms)			/* (Elf32_Sym + entry)->Elf32_Syms			*/
#define PFILE_SYM_SYMS_P(entry)		(&(PFILE_SYM_SYMS(entry)))			/* &((Elf32_Sym + entry)->Elf32_Syms			*/
#define PFILE_SYM_SYMS_ELEMS(entry)	(PFILE_SYM_SYMS(entry)->Elems)			/* (Elf32_Sym + entry)->Elf32_Syms->Elems		*/

#define PFILE_SYM_TABLE(entry)		(PFILE_SYM_SYMS(entry)->SymbolTable)		/* (Elf32_Sym + entry)->Elf32_Syms->SymbolTable		*/
#define PFILE_SYM_TABLE_P(entry)	(&(PFILE_SYM_TABLE(entry)))			/* &((Elf32_Sym + entry)->Elf32_Sym->SymbolTable)	*/

