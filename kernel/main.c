
long	nFiles;
_Bool	DisplayELFHeader = 1;
_Bool	DisplayELFSections = 1;
_Bool	DisplayELFSymbolTable = 1;

int
main(int argc,char *argv[])
{
	nFiles = argc - 1;
	Elf32_InitPointers();
	Elf32_ReadELFHeader(argv);
	Elf32_getELFSections(argv);
	Elf32_getSymbolTable(argv);
	return (0);
}
