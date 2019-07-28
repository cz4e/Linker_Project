
/*
 * used e_machine
 */
/* Values for e_type. */
#define	ET_NONE		0	/* Unknown type. */
#define	ET_REL		1	/* Relocatable. */
#define	ET_EXEC		2	/* Executable. */
#define	ET_DYN		3	/* Shared object. */
#define	ET_CORE		4	/* Core file. */
#define	ET_LOOS		0xfe00	/* First operating system specific. */
#define	ET_HIOS		0xfeff	/* Last operating system-specific. */
#define	ET_LOPROC	0xff00	/* First processor-specific. */
#define	ET_HIPROC	0xffff	/* Last processor-specific. */
#define ET_NUMBER	9

/* Values for e_machine. */
#define	EM_NONE		0	/* Unknown machine. */
#define	EM_M32		1	/* AT&T WE32100. */
#define	EM_SPARC	2	/* Sun SPARC. */
#define	EM_386		3	/* Intel i386. */
#define	EM_68K		4	/* Motorola 68000. */
#define	EM_88K		5	/* Motorola 88000. */
#define	EM_IAMCU	6	/* Intel MCU. */
#define	EM_860		7	/* Intel i860. */
#define	EM_MIPS		8	/* MIPS R3000 Big-Endian only. */
#define	EM_S370		9	/* IBM System/370. */
#define	EM_MIPS_RS3_LE	10	/* MIPS R3000 Little-Endian. */
#define	EM_PARISC	15	/* HP PA-RISC. */
#define	EM_VPP500	17	/* Fujitsu VPP500. */
#define	EM_SPARC32PLUS	18	/* SPARC v8plus. */
#define	EM_960		19	/* Intel 80960. */
#define	EM_PPC		20	/* PowerPC 32-bit. */
#define	EM_PPC64	21	/* PowerPC 64-bit. */
#define	EM_S390		22	/* IBM System/390. */
#define	EM_V800		36	/* NEC V800. */
#define	EM_FR20		37	/* Fujitsu FR20. */
#define	EM_RH32		38	/* TRW RH-32. */
#define	EM_RCE		39	/* Motorola RCE. */
#define	EM_ARM		40	/* ARM. */
#define	EM_SH		42	/* Hitachi SH. */
#define	EM_SPARCV9	43	/* SPARC v9 64-bit. */
#define	EM_TRICORE	44	/* Siemens TriCore embedded processor. */
#define	EM_ARC		45	/* Argonaut RISC Core. */
#define	EM_H8_300	46	/* Hitachi H8/300. */
#define	EM_H8_300H	47	/* Hitachi H8/300H. */
#define	EM_H8S		48	/* Hitachi H8S. */
#define	EM_H8_500	49	/* Hitachi H8/500. */
#define	EM_IA_64	50	/* Intel IA-64 Processor. */
#define	EM_MIPS_X	51	/* Stanford MIPS-X. */
#define	EM_COLDFIRE	52	/* Motorola ColdFire. */
#define	EM_68HC12	53	/* Motorola M68HC12. */
#define	EM_MMA		54	/* Fujitsu MMA. */
#define	EM_PCP		55	/* Siemens PCP. */
#define	EM_NCPU		56	/* Sony nCPU. */
#define	EM_NDR1		57	/* Denso NDR1 microprocessor. */
#define	EM_STARCORE	58	/* Motorola Star*Core processor. */
#define	EM_ME16		59	/* Toyota ME16 processor. */
#define	EM_ST100	60	/* STMicroelectronics ST100 processor. */
#define	EM_TINYJ	61	/* Advanced Logic Corp. TinyJ processor. */
#define	EM_X86_64	62	/* Advanced Micro Devices x86-64 */
#define	EM_AMD64	EM_X86_64	/* Advanced Micro Devices x86-64 (compat) */
#define	EM_PDSP		63	/* Sony DSP Processor. */
#define	EM_FX66		66	/* Siemens FX66 microcontroller. */
#define	EM_ST9PLUS	67	/* STMicroelectronics ST9+ 8/16
				   microcontroller. */
#define	EM_ST7		68	/* STmicroelectronics ST7 8-bit
				   microcontroller. */
#define	EM_68HC16	69	/* Motorola MC68HC16 microcontroller. */
#define	EM_68HC11	70	/* Motorola MC68HC11 microcontroller. */
#define	EM_68HC08	71	/* Motorola MC68HC08 microcontroller. */
#define	EM_68HC05	72	/* Motorola MC68HC05 microcontroller. */
#define	EM_SVX		73	/* Silicon Graphics SVx. */
#define	EM_ST19		74	/* STMicroelectronics ST19 8-bit mc. */
#define	EM_VAX		75	/* Digital VAX. */
#define	EM_CRIS		76	/* Axis Communications 32-bit embedded
				   processor. */
#define	EM_JAVELIN	77	/* Infineon Technologies 32-bit embedded
				   processor. */
#define	EM_FIREPATH	78	/* Element 14 64-bit DSP Processor. */
#define	EM_ZSP		79	/* LSI Logic 16-bit DSP Processor. */
#define	EM_MMIX		80	/* Donald Knuth's educational 64-bit proc. */
#define	EM_HUANY	81	/* Harvard University machine-independent
				   object files. */
#define	EM_PRISM	82	/* SiTera Prism. */
#define	EM_AVR		83	/* Atmel AVR 8-bit microcontroller. */
#define	EM_FR30		84	/* Fujitsu FR30. */
#define	EM_D10V		85	/* Mitsubishi D10V. */
#define	EM_D30V		86	/* Mitsubishi D30V. */
#define	EM_V850		87	/* NEC v850. */
#define	EM_M32R		88	/* Mitsubishi M32R. */
#define	EM_MN10300	89	/* Matsushita MN10300. */
#define	EM_MN10200	90	/* Matsushita MN10200. */
#define	EM_PJ		91	/* picoJava. */
#define	EM_OPENRISC	92	/* OpenRISC 32-bit embedded processor. */
#define	EM_ARC_A5	93	/* ARC Cores Tangent-A5. */
#define	EM_XTENSA	94	/* Tensilica Xtensa Architecture. */
#define	EM_VIDEOCORE	95	/* Alphamosaic VideoCore processor. */
#define	EM_TMM_GPP	96	/* Thompson Multimedia General Purpose
				   Processor. */
#define	EM_NS32K	97	/* National Semiconductor 32000 series. */
#define	EM_TPC		98	/* Tenor Network TPC processor. */
#define	EM_SNP1K	99	/* Trebia SNP 1000 processor. */
#define	EM_ST200	100	/* STMicroelectronics ST200 microcontroller. */
#define	EM_IP2K		101	/* Ubicom IP2xxx microcontroller family. */
#define	EM_MAX		102	/* MAX Processor. */
#define	EM_CR		103	/* National Semiconductor CompactRISC
				   microprocessor. */
#define	EM_F2MC16	104	/* Fujitsu F2MC16. */
#define	EM_MSP430	105	/* Texas Instruments embedded microcontroller
				   msp430. */
#define	EM_BLACKFIN	106	/* Analog Devices Blackfin (DSP) processor. */
#define	EM_SE_C33	107	/* S1C33 Family of Seiko Epson processors. */
#define	EM_SEP		108	/* Sharp embedded microprocessor. */
#define	EM_ARCA		109	/* Arca RISC Microprocessor. */
#define	EM_UNICORE	110	/* Microprocessor series from PKU-Unity Ltd.
				   and MPRC of Peking University */
#define	EM_AARCH64	183	/* AArch64 (64-bit ARM) */
#define	EM_RISCV	243	/* RISC-V */
#define EM_NUMBER	114

#define	SHF_WRITE		0x1	/* Section contains writable data. */
#define	SHF_ALLOC		0x2	/* Section occupies memory. */
#define	SHF_EXECINSTR		0x4	/* Section contains instructions. */
#define	SHF_MERGE		0x10	/* Section may be merged. */
#define	SHF_STRINGS		0x20	/* Section contains strings. */
#define	SHF_INFO_LINK		0x40	/* sh_info holds section index. */
#define	SHF_LINK_ORDER		0x80	/* Special ordering requirements. */
#define	SHF_OS_NONCONFORMING	0x100	/* OS-specific processing required. */
#define	SHF_GROUP		0x200	/* Member of section group. */
#define	SHF_TLS			0x400	/* Section contains TLS data. */
#define	SHF_COMPRESSED		0x800	/* Section contains compressed data. */
#define	SHF_MASKOS	0x0ff00000	/* OS-specific semantics. */
#define	SHF_MASKPROC	0xf0000000	/* Processor-specific semantics. */


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
