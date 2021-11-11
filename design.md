# ExVM Design

- Written in C
- Value destinations passed into functions
- Functions that can error return an int
- Instruction format
	- 1 byte opcode
	- 4 byte uint32_t operand
- Every instruction is passed a pointer to the "Machine" structure and uses a corresponding function to modify the state
	- ex. Push, Pop, Error (Error has not been implemented yet)

## Machine Execution

- The machine loads a program into its memory
- The program counter starts at 0
- The machine will have a step function that executes the current instruction pointed at by the program counter
- The step function will return an error if the program has encountered an errored state
	- This error state will prevent step from further executing instructions until the machine is reset
	- This behavior is intended to prevent someone from further corrupting the machine state and potentially exposing a vulnerability

## Machine Error Handling

- Instructions or procedures will be able to return an error through the int return type
- This return would then be used to halt execution of the machine
	- Could be done using a flag

## Extending the machine

- Custom instructions for a machine instance will be called using a call opcode with the operand being the identifier for the custom function
- Not sure how to make this efficient
	- Should the instructions be statically resolved and inserted, or should a dynamic lookup be used?
- Implementation idea 1
	- A library of procedures could be treated as a pointer to an array of function pointers defined within the library
	- The library name would be set as some integer with the corresponding function indexed from the library
	- This method reduces the amount of memory needed to store all pointers
		- The end user would be responsible for providing the library array to the machine on creation
	- In the future:
		- Compiling programs could use some kind of library description to convert function names into the library index and function pointer
		```json
{
	"libraries": [
		[
		"func1",
		"func2",
		"func3"
		]
	]
}

		```

