`timescale 1ns/1ps

// User-defined Primitives Modelling (truth table)

module simple_circuit(D, E, A, B, C);
	input A, B, C;
	output D, E;
	
    UDP_D(D, A, B, C);
    UDP_E(E, A, B, C);
	
endmodule

primitive UDP_D(D, A, B, C);
    output D;
    input A, B, C;

    table 
    // A B C : D
        0 0 0 : 1;
        0 0 1 : 0;
        0 1 0 : 1;
        0 1 1 : 0;
        1 0 0 : 1;
        1 0 1 : 0;
        1 1 0 : 1;
        1 1 1 : 1;
    endtable
endprimitive


primitive UDP_E(E, A, B, C);
    output E;
    input A, B, C;

    table 
    // A B C : E
        0 0 0 : 1;
        0 0 1 : 0;
        0 1 0 : 1;
        0 1 1 : 0;
        1 0 0 : 1;
        1 0 1 : 0;
        1 1 0 : 1;
        1 1 1 : 0;
    endtable
endprimitive
