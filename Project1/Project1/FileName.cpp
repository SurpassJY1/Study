#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <bitset>

// Define the memory size and word size
#define MEMORY_SIZE 32
#define WORD_SIZE 32

class ManchesterBaby {
private:
    std::vector<uint32_t> memory;  // Memory for the emulator
    uint32_t accumulator;           // Accumulator for arithmetic operations
    uint32_t instructionRegister;   // Holds the current instruction
    uint32_t programCounter;        // Points to the next instruction to be executed

public:
    ManchesterBaby() : memory(MEMORY_SIZE, 0), accumulator(0), instructionRegister(0), programCounter(0) {} // Constructor to initialize the machine

    void loadProgram(const std::string& filename);  // Load the program into memory
    int fetch();                                      // Fetch the instruction from memory
    int execute();                                    // Execute the fetched instruction
    void printState() const;                          // Print the current state of the machine
    void printBinary(uint32_t num, int bits) const;  // Print a number in binary format

private:
    int isBinary(const std::string& str) const;      // Check if a string is a valid binary string
    int validateAddress(uint32_t address) const;     // Validate a memory address
    int checkOverflow(uint32_t a, uint32_t b) const; // Check for overflow in arithmetic operations
};

// Enumeration for opcodes (operation codes)
enum Opcode {
    LOAD = 0x00,
    STORE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    SHIFT_LEFT,
    OUTPUT,
    HALT
};

// Main function, entry point of the program
int main(int argc, char* argv[]) {
    // Check for proper command line arguments
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <program_file>\n";
        return EXIT_FAILURE;
    }
    assemble(argv[1], argv[2]);
    ManchesterBaby manchesterBaby; // Instantiate the ManchesterBaby emulator
    manchesterBaby.loadProgram(argv[2]); // Load the specified program file

    // Loop to continue fetching and executing instructions
    while (true) {
        // Fetch the next instruction and check for errors
        if (manchesterBaby.fetch() == -1) {
            std::cerr << "Fetching failure, exiting...\n";
            break;
        }

        // Execute the fetched instruction and check for errors
        if (manchesterBaby.execute() == -1) {
            std::cerr << "Execution failure, exiting...\n";
            break;
        }

        manchesterBaby.printState(); // Print the current state after execution
    }

    return EXIT_SUCCESS; // Exit successfully
}

// Method to load a program from a binary file into memory
void ManchesterBaby::loadProgram(const std::string& filename) {
    std::ifstream file(filename); // Open the program file
    if (!file.is_open()) { // Check if file opened successfully
        std::cerr << "Failed to open program file\n";
        exit(EXIT_FAILURE);
    }

    std::string buffer;
    // Read each line of the file into memory
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!std::getline(file, buffer)) // Read a line
            break;

        // Validate the binary input
        if (!isBinary(buffer)) {
            std::cerr << "Invalid binary string: " << buffer << "\n";
            exit(EXIT_FAILURE);
        }

        // Convert binary string to unsigned integer and store in memory
        memory[i] = static_cast<uint32_t>(std::stoul(buffer, nullptr, 2));
    }

    // Check for potential issues with reading the file
    if (file.eof() && !file.fail() && file.gcount() > 0) {
        std::cerr << "Warning: Program size exceeded MEMORY_SIZE; truncated input.\n";
    }
    else if (file.fail()) {
        std::cerr << "Error reading program file\n";
    }

    file.close();
}

// Fetch method to retrieve the next instruction from memory
int ManchesterBaby::fetch() {
    // Validate program counter is within valid bounds
    if (programCounter < 0 || programCounter >= MEMORY_SIZE) {
        std::cerr << "Program Counter out of bounds, potential infinite loop.\n";
        return -1;
    }

    instructionRegister = memory[programCounter]; // Load the instruction into the IR
    programCounter++; // Increment the program counter for next fetch

    return 0;
}

// Execute the fetched instruction
int ManchesterBaby::execute() {
    if (instructionRegister == 0) {
        return 0;
    }

    uint32_t opcode = (instructionRegister >> 30) & 0x03; // Extract opcode
    uint32_t address = instructionRegister & 0x3FFFFFFF; // Extract memory address

    // Check for unknown 
    if (opcode > HALT) {
        std::cerr << "Unknown opcode: " << opcode << "\n";
        return -1;
    }

    // Validate memory address
    if (validateAddress(address) == -1) {
        return -1;
    }

    // Switch-case to handle different opcodes
    switch (opcode) {
    case LOAD:
        accumulator = memory[address]; // Load value from memory into accumulator
        break;
    case STORE:
        if (validateAddress(address) == -1) return -1; // Validation on STORE
        memory[address] = accumulator; // Store accumulator value into memory
        break;
    case ADD:
        if (checkOverflow(accumulator, memory[address])) { // Check for overflow
            std::cerr << "Overflow detected during ADD\n";
            return -1;
        }
        accumulator += memory[address]; // Add memory value to accumulator
        break;
    case SUBTRACT:
        if (accumulator < memory[address]) { // Check for underflow
            std::cerr << "Underflow detected during SUBTRACT\n";
            return -1;
        }
        accumulator -= memory[address]; // Subtract memory value from accumulator
        break;
    case MULTIPLY:
        if (checkOverflow(accumulator, memory[address])) { // Check for overflow
            std::cerr << "Overflow detected during MULTIPLY\n";
            return -1;
        }
        accumulator *= memory[address]; // Multiply accumulator with memory value
        break;
    case SHIFT_LEFT:
        accumulator <<= 1; // Shift accumulator left by 1 bit
        break;
    case OUTPUT:
        // Print the current value of the accumulator in decimal and binary
        std::cout << "Output: " << accumulator << " (in binary: ";
        printBinary(accumulator, WORD_SIZE);
        std::cout << ")\n";
        break;
    case HALT:
        std::cout << "Halting execution.\n"; // Indicate halt
        return -1;
    default:
        std::cerr << "Unknown opcode: " << opcode << "\n"; // Handle unknown opcode
        return -1;
    }

    return 0;
}

// Print the current state of the Manchester Baby machine
void ManchesterBaby::printState() const {
    std::cout << "PC: " << programCounter
        << ", IR: ";
    printBinary(instructionRegister, WORD_SIZE); // Print instruction register in binary
    std::cout << ", AC: ";
    printBinary(accumulator, WORD_SIZE); // Print accumulator in binary
    std::cout << "Memory:\n";
    std::cout << "Address | Value\n";
    std::cout << "--------|----------------\n";
    // Print each memory address with its corresponding value in binary
    for (int i = 0; i < MEMORY_SIZE; i++) {
        std::cout << " " << i << " | ";
        printBinary(memory[i], WORD_SIZE);
    }
    std::cout << "\n"; // New line after memory printout
}

// Utility method to print a number in binary format
void ManchesterBaby::printBinary(uint32_t num, int bits) const {
    std::cout << std::bitset<WORD_SIZE>(num); // Convert number to binary
    std::cout << '\n'; // New line after printing binary
}

// Check if a string is a valid binary representation
int ManchesterBaby::isBinary(const std::string& str) const {
    return str.find_first_not_of("01") == std::string::npos; // Check for any non-binary characters
}

// Validate if a memory address is within acceptable bounds
int ManchesterBaby::validateAddress(uint32_t address) const {
    if (address >= MEMORY_SIZE) {
        std::cerr << "Invalid memory address: " << address << "\n"; // Invalid address message
        return -1;
    }
    return 0;
}

// Check for potential overflow during addition/multiplication
int ManchesterBaby::checkOverflow(uint32_t a, uint32_t b) const {
    return (a > UINT32_MAX - b); // Check if addition would result in overflow
}
