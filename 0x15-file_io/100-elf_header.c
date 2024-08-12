#include "main.h"

/**
 * check_elf_file - checks if file is elf
 *
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void check_elf_file(unsigned char *e_ident)
{
	int counter;

	for (counter = 0; counter < 4; counter++)
	{
		if (e_ident[counter] != 127 && e_ident[counter] != 'E'
		&& e_ident[counter] != 'L' && e_ident[counter] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not and ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_elf_magic - prints magic section of the elf file
 *
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void print_elf_magic(unsigned char *e_ident)
{
	int counter;

	printf("  Magic:   ");
	for (counter = 0; counter < EI_NIDENT; counter++)
	{
		printf("%02x", e_ident[counter]);
		if (counter == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_elf_class - prints class section of the elf file
 *
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void print_elf_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	if (e_ident[4] == ELFCLASSNONE)
		printf("none\n");
	else if (e_ident[4] == ELFCLASS64)
		printf("ELF64\n");
	else if (e_ident[4] == ELFCLASS32)
		printf("ELF32\n");
	else
		printf("<unknown: %x>\n", e_ident[4]);
}

/**
 * print_elf_data - prints data section of the elf file
 *
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void print_elf_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	if (e_ident[5] == ELFDATANONE)
		printf("none\n");
	else if (e_ident[5] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[5] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_ident[5]);
}

/**
 * print_elf_version - prints version section of the elf file
 *
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void print_elf_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[6]);
	if (e_ident[6] == EV_NONE)
		printf("\n");
	else
		printf(" (current)\n");
}

/**
 * print_elf_osabi - prints osabi section of the elf file
 *
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void print_elf_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	if (e_ident[7] == ELFOSABI_NONE || e_ident == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (e_ident[7] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (e_ident[7] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[7] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e_ident[7] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (e_ident[7] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (e_ident[7] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (e_ident[7] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (e_ident[7] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (e_ident[7] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", e_ident[7]);
	printf("  ABI Version:                       %d\n", e_ident[8]);
}

/**
 * print_elf_type - prints type section of the elf file
 *
 * @e_type: file type
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void print_elf_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");
	if (e_type == ET_NONE)
		printf("NONE (none)");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<Unknown: %x>\n", e_type);
}

/**
 * print_elf_addr - prints addr section of the elf file
 *
 * @e_entry: virtual address
 * @e_ident: pointer to array of magic numbers
 *
 * Return: void
 */
void print_elf_addr(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("  Entry point address:               %#x\n", (unsigned int)e_entry);
	else
		printf("  Entry point address:               %#lx\n", e_entry);
}


/**
 * close_elf_file - closes elf file
 *
 * @fd: file descriptor
 *
 * Return: void
 */
void close_elf_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Can't close fd %d", fd);
		exit(98);
	}
}

/**
 * main - reads elf file header
 *
 * @argc: number or arguments
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int open_header, read_header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	open_header = open(argv[1], O_RDONLY);
	if (open_header == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_file(open_header);
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}
	read_header = read(open_header, header, sizeof(Elf64_Ehdr));
	if (read_header == -1)
	{
		free(header);
		close_elf_file(open_header);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	check_elf_file(header->e_ident);
	printf("ELF Header:\n");
	print_elf_magic(header->e_ident);
	print_elf_class(header->e_ident);
	print_elf_data(header->e_ident);
	print_elf_version(header->e_ident);
	print_elf_osabi(header->e_ident);
	print_elf_type(header->e_type, header->e_ident);
	print_elf_addr(header->e_entry, header->e_ident);
	return (0);
}
