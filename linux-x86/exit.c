/*
 * (linux/x86) normal exit w/ random (so to speak) return value - 5 bytes
 * - Itzik Kotler <ik@ikotler.org>
 */

char shellcode[] = 

	"\x31\xc0"              // xor %eax,%eax 
	"\x40"                  // inc %eax 
	"\xcd\x80";             // int $0x80 

int main(int argc, char **argv) {
	int *ret;
	ret = (int *)&ret + 2;
	(*ret) = (int) shellcode;
}
