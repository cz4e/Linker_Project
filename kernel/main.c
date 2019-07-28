
long	nFiles;
_Bool	DisplayELFHeader = 1;
_Bool	DisplayELFSections = 1;

int
main(int argc,char *argv[])
{
	nFiles = argc - 1;
	Elf32_ReadELF(argv);
	return (0);
}
