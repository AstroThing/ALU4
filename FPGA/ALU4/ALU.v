`timescale 1ns / 1ps

module ALU(
		input [3:0] a,
		input [3:0] b,
		input [2:0] _function,
		output reg [3:0] result
    );

	parameter ADD = 4'h0;
	parameter SUB = 4'h1;
	parameter AND = 4'h2;
	parameter OR = 4'h3;
	parameter XOR = 4'h4;
	
	always @ (a or b or _function)
	begin
		case(_function)
			ADD: result = a + b;
			SUB: result = a - b;
			AND: result = a & b;
			OR: result = a | b;
			XOR: result = a ^ b;
			default: result = 4'h0;
		endcase
	end
	
endmodule
