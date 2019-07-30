
#define ET_NUMBER	9

#define EM_NUMBER	114

#define MAX_SECTION_FLAGS	13

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
char *FileTypes[ET_NUMBER] = {
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


char *MachineTypes[EM_NUMBER + 1] = {
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

#define MAX_SYMBOL_BIND		8

const char *SymbolTableBind[MAX_SYMBOL_BIND] = {
			"LOCAL",
			"GLOBAL",
			"WEAK",
			"LOOS",
			"UNIQUE",
			"HIOS",
			"LOPROC",
			"HIPROC"
			};
#define MAX_SYMBOL_TYPE		16
const char *SymbolTableType[MAX_SYMBOL_TYPE] = {
			"NOTYPE",	/* 0 */
			"OBJECT",	/* 1 */
			"FUNC",		/* 2 */
			"SECTION",	/* 3 */
			"FILE",		/* 4 */
			"COMMON",	/* 5 */
			"TLS",		/* 6 */
			"NUM",		/* 7 */
			"LOOS",		/* 8 */
			"IFUNC",	/* 9 */
			"HIOS",	 	/* 10*/
			"",
			"HIPROC"	/* 12*/
			};
