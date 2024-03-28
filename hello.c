#include <efi.h>
#include <efilib.h>
#include <stdbool.h>

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	EFI_STATUS Status;
	EFI_INPUT_KEY Key;

	ST = SystemTable;

	UINTN i = 0;

	while (i<100000) {
		Status = ST->ConOut->Reset(ST->ConOut, FALSE);

		Status = ST->ConOut->OutputString(ST->ConOut, L"Welcome to Booting Basics\r\n\r\nPress any key to continue...\r\n");
		if (EFI_ERROR(Status))
			return Status;

		Status = ST->ConIn->Reset(ST->ConIn, FALSE);
		if (EFI_ERROR(Status))
			return Status;

		while ((Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key)) == EFI_NOT_READY);

		Status = ST->ConOut->Reset(ST->ConOut, FALSE);
		Status = ST->ConOut->OutputString(ST->ConOut, L"BIOS\r\n\r\n\r\nThe first steps in the booting process of any computer is a series of tests of\r\nhardware, ensuring that the computer has adequate power and that everything\r\nis in working order.\r\n\r\nWhile performing these tests, the computer also clears out its memory and CPU\r\nto prevent any unintended code from running.\r\n\r\nIt then loads firmware from a non-volatile(persistent) memory chip which is\r\nable to read the computer's storage and run programs stored in a\r\npre-specified place.\r\n\r\nIn the case of this and most modern computers, the firmware conforms to UEFI\r\nspecifications and runs EFI applications, like this one.\r\n\r\n\r\nPotential Optimizations:\r\n- None\r\n\r\n\r\nPress any key to continue...");
		Status = ST->ConIn->Reset(ST->ConIn, FALSE);
		while ((Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key)) == EFI_NOT_READY);
		Status = ST->ConOut->Reset(ST->ConOut, FALSE);
		Status = ST->ConOut->OutputString(ST->ConOut, L"Bootloader\r\n\r\nIn an average booting process, the EFI application called would be a\r\nbootloader, which is tasked with finding and loading the operating system.\r\n\r\nA bootloader does this by loading its configuration and searching the places\r\n(directories) listed in the config for the kernel and initial RAM.\r\n\r\nThe kernel is what handles all communication with the computer's hardware\r\nand the user for the operating system, while the initial RAM is a copy of\r\ndrivers and programs to load into memory so the kernel can take control.\r\n\r\n\r\nPotential Optimizations:\r\n- Reduction of compatibility features\r\n- Specialized memory chip storing kernel and initial RAM bypassing need for\r\nbootloader\r\n\r\n\r\nPress any key to continue...");
		Status = ST->ConIn->Reset(ST->ConIn, FALSE);
		while ((Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key)) == EFI_NOT_READY);
		Status = ST->ConOut->Reset(ST->ConOut, FALSE);
		Status = ST->ConOut->OutputString(ST->ConOut, L"Kernel and Init\r\n\r\n\r\nThe final step of the boot process are the kernel takeover and the start\r\nof the initial process(init).\r\n\r\nOnce the kernel has been loaded, it takes over running the system from the\r\nfirmware and starts an initial program that is in charge of starting all\r\nother programs on the system.\r\n\r\nIn the boot process, init has the job of starting all required processes\r\nfor user runtime (i.e. Graphics, WiFi, User Authentication, etc.) in a\r\ntimely manner.\r\n\r\nThis is either done with a script for init to follow or in the case of\r\nSystemd, become a majority of these processes.\r\n\r\n\r\nPotential Optimizations:\r\n- Reduce the number of needed processes at startup(and in turn\r\ncompatibility)\r\n\r\n\r\nPress any key to reset.");
		Status = ST->ConIn->Reset(ST->ConIn, FALSE);
		while ((Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key)) == EFI_NOT_READY);

		i += 1;
	}	
	return Status;
	
}
