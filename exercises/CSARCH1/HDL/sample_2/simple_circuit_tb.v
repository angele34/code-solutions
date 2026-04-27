`timescale 1ns/1ps

module simple_circuit_tb ();
    reg t_A, t_B, t_C;
    wire t_D, t_E;

    simple_circuit dut(t_D, t_E, t_A, t_B, t_C);
    
    initial begin
        t_A = 0; t_B = 0; t_C = 0;
        #10 t_A = 0; t_B = 0; t_C = 1;
        #10 t_A = 0; t_B = 1; t_C = 0;
        #10 t_A = 0; t_B = 1; t_C = 1;
        #10 t_A = 1; t_B = 0; t_C = 0;
        #10 t_A = 1; t_B = 0; t_C = 1;
        #10 t_A = 1; t_B = 1; t_C = 0;
        #10 t_A = 1; t_B = 1; t_C = 1;
        #10 $finish;
    end

    initial begin
        $monitor("time = %d: A = %b B = %b C = %b | D = %b E = %b",
        $time, t_A, t_B, t_C, t_D, t_E);
        $dumpfile("simple_circuit.vcd");
        $dumpvars(0, simple_circuit_tb);
    end

endmodule
