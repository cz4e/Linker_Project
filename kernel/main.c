
int nFiles;
_Bool DisplayHeader = 0;
_Bool DisplaySection = 0;
_Bool DisplaySymTab = 0;

int
main(int argc,char *FileName[])
{
	DisplayHeader = 1;
	DisplaySection = 1;
	DisplaySymTab = 1;
	nFiles = argc - 1;
	Elf32_ReadELFHeader(FileName);
	return (0);
}
