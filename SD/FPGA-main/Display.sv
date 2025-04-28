module display(
    input logic [3:0] data,
    output logic a, b, c, d, e, f, g, dp
);

    logic [7:0] ff [0:9] = {
        8'b1111110_0, // 0
        8'b0110000_0, // 1
        8'b1101101_0, // 2
        8'b1111001_0, // 3
        8'b0110011_0, // 4
        8'b1011011_0, // 5
        8'b1011111_0, // 6
        8'b1110000_0, // 7
        8'b1111111_0, // 8
        8'b1110011_0  // 9
    };

    always_comb begin
        {a, b, c, d, e, f, g, dp} = 8'b0000000_0;
        if (data < 10)
            {a, b, c, d, e, f, g, dp} = ff[data];
    end
endmodule