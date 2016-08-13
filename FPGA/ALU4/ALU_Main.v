`timescale 1ns / 1ps

module ALU_Main(
		input [3:0] a,
		input [3:0] b,
		input [2:0] _function,
		output [3:0] result
    );

	ALU alu(a, b, _function, result);
	
endmodule
