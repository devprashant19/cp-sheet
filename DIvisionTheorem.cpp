#include <iostream>
#include <vector>
#include <string>
#include <cmath>    
#include <cstdlib>  
#include <iomanip>
using namespace std;
// This sets the register width for A, B, and Q magnitudes.
// Range for Unsigned Magnitude: 0 to 31 (2^5 - 1)
const int n = 5; 

// Prints a number in binary (n bits)
void printReg(string name, int val) {
    cout << name << "=";
    for (int i = n - 1; i >= 0; i--) {
        cout << ((val >> i) & 1);
    }
    cout << " ";
}

// Function: Add (Returns Sum, updates Carry E)
int add(int A, int B, int& E) {
    int sum = A + B;
    int mask = (1 << n) - 1;
    
    // Check Carry (Bit n)
    if (sum > mask) E = 1; 
    else E = 0;
    
    return sum & mask; // Keep only n bits
}

// Function: Subtract (A + B' + 1)
// Used to check A >= B or to perform subtraction
int subtract(int A, int B, int& E) {
    int mask = (1 << n) - 1;
    int B_complement = (~B) & mask; // One's complement
    int sum = A + B_complement + 1; // Two's complement addition
    
    // In subtraction A - B:
    // If Carry (E) is 1, result is Positive (A >= B)
    // If Carry (E) is 0, result is Negative (A < B)
    if (sum > mask) E = 1; 
    else E = 0;            
    
    return sum & mask;
}

int main() {
    // --- INPUTS (Test Case for 5 Bits) ---
    // Example: 21 / 4
    // 21 in binary (5 bits) = 10101
    // 4  in binary (5 bits) = 00100
    int dividend_in = 21; 
    int divisor_in = 4;   

    cout << "========================================" << endl;
    cout << "   5-BIT DIVISION ALGORITHM SIMULATION   " << endl;
    cout << "========================================" << endl;
    cout << "Input: " << dividend_in << " / " << divisor_in << endl;

    // --- 1. INITIALIZATION ---
    // Handle Signs separately (as per top of flowchart)
    int As_sign = (dividend_in < 0) ? 1 : 0;
    int Bs_sign = (divisor_in < 0) ? 1 : 0;
    int Qs = As_sign ^ Bs_sign; // XOR signs

    // Initialize Registers
    int A = 0; 
    int B = abs(divisor_in);
    int Q = abs(dividend_in);
    int E = 0;
    int SC = n - 1; // Flowchart: SC <- n - 1 (starts at 4)
    int DVF = 0;    // Overflow flag

    // Mask inputs to strictly 5 bits
    int mask = (1 << n) - 1;
    Q &= mask;
    B &= mask;

    cout << "Initial State:" << endl;
    cout << "  "; printReg("A", A); printReg("Q", Q); printReg("B", B); 
    cout << " SC=" << SC << endl;
    cout << "----------------------------------------" << endl;

    // --- 2. DIVIDE OVERFLOW CHECK ---
    // Flowchart: EA <- A + B' + 1
    cout << "[Step] Overflow Check (A - B)" << endl;
    int A_temp = A; // Save A
    A = subtract(A, B, E);
    
    cout << "  Result: E=" << E << " "; printReg("A", A); cout << endl;

    // Check E (Top Diamond)
    if (E == 1) {
        // Path: 1 (True) -> Overflow
        cout << "  [Condition] E==1 (A >= B)" << endl;
        // Restore A (EA <- A + B)
        A = add(A, B, E);
        DVF = 1;
        cout << "  >> Action: DVF <- 1. END (Overflow)." << endl;
        return 0; 
    } else {
        // Path: 0 (False) -> No Overflow
        cout << "  [Condition] E==0 (A < B)" << endl;
        // Restore A (EA <- A + B)
        A = add(A, B, E);
        DVF = 0;
        cout << "  >> Action: DVF <- 0. Proceeding..." << endl;
    }

    // --- 3. MAIN LOOP ---
    // The flowchart implies a loop that runs while checking SC at the end.
    do {
        cout << "\n--- Loop Iteration (Start SC=" << SC << ") ---" << endl;

        // a. Shift Left EAQ
        cout << "  [Action] shl EAQ" << endl;
        E = (A >> (n - 1)) & 1;          // MSB of A moves to E
        int Q_msb = (Q >> (n - 1)) & 1;  // MSB of Q moves to LSB of A
        A = ((A << 1) | Q_msb) & mask;   // Shift A
        Q = (Q << 1) & mask;             // Shift Q
        
        cout << "    State: E=" << E << " "; printReg("A", A); printReg("Q", Q); cout << endl;

        // b. Check E (Middle Diamond)
        if (E == 1) {
            // Path: E=1
            cout << "  [Condition] E==1" << endl;
            // A <- A + B' + 1 (Subtract B)
            A = subtract(A, B, E);
            cout << "    Subtracted B: "; printReg("A", A); cout << endl;
            
            // Q0 <- 1 (Unconditional)
            Q = Q | 1;
            cout << "    Set Q[0] <- 1" << endl;
        } 
        else { 
            // Path: E=0
            cout << "  [Condition] E==0" << endl;
            // EA <- A + B' + 1 (Subtract B)
            A = subtract(A, B, E);
            cout << "    Subtracted B. Check Result E: " << E << endl;

            if (E == 1) {
                // Inner Path: 1 (Result Positive)
                cout << "    [Condition] Result E==1 (A >= B)" << endl;
                Q = Q | 1; // Q0 <- 1
                cout << "    Set Q[0] <- 1" << endl;
            } else {
                // Inner Path: 0 (Result Negative)
                cout << "    [Condition] Result E==0 (A < B)" << endl;
                // EA <- A + B (Restore A)
                A = add(A, B, E);
                cout << "    Restore A: "; printReg("A", A); cout << endl;
                // Q0 remains 0
            }
        }

        // c. Decrement SC
        SC = SC - 1;
        
        // d. Check SC (Bottom Diamond)
        // Loop continues if SC != 0
    } while (SC != 0);

    // --- 4. FINAL RESULT ---
    cout << "========================================" << endl;
    cout << "Final Results:" << endl;
    cout << "  Quotient (Q):  "; printReg("Q", Q); cout << " = " << Q << endl;
    cout << "  Remainder (A): "; printReg("A", A); cout << " = " << A << endl;

    // Apply Signs
    int final_Q = (Qs == 1) ? -Q : Q;
    int final_R = (dividend_in < 0) ? -A : A;

    cout << "  Signed Quotient:  " << final_Q << endl;
    cout << "  Signed Remainder: " << final_R << endl;
    cout << "========================================" << endl;

    return 0;
}