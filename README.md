# Circuit Analyzer

Calculating the total resistance of a circuit is essential for analyzing any electrical circuit. This program enables users to input a circuit description and applied voltage, and it calculates the total resistance and circuit current.

## Program Description

- The program allows users to describe mixed types of connections in a circuit.
- Users can choose the type of connection (series or parallel) followed by the values of as many resistances as they want, separated by one space.
- The program handles different connection types within the same circuit description.
- If the user provides an incorrect connection type, the program displays a warning message.
- The circuit description ends with an 'E' to indicate the end of the description.
- The program is modular and has user-defined functions to calculate the total resistance for different types of connections (series and parallel).

## Usage

1. **Input Circuit Description**: Provide a description of the circuit, including the type of connections ('S' for series or 'P' for parallel), followed by the resistance values separated by spaces. Use 'E' to indicate the end of each connection and 'E' at the end to signal the end of the circuit description.

2. **Input Applied Voltage**: Enter the voltage applied to the circuit.

3. **Output**: The program calculates the total resistance and circuit current. If the circuit description is invalid, it displays a warning message.

## Example

- Circuit description: S 10 20 e P 30 40 50 e P 60 70 e E
- Applied voltage: 10
- Total resistance = 226.667 ohm
- Circuit current = 0.441 A
- In this example, the circuit consists of three branches: the first branch is in series, the second and third branches are in parallel. The applied voltage is 100V, and the calculated total resistance is 226.667 ohms with a circuit current of 0.441 A.

## Implementation Details

- The program utilizes modular functions to calculate total resistance for series and parallel connections.
- It checks for the validity of the circuit description to ensure accurate calculations.
- The code is structured for readability and maintainability.

