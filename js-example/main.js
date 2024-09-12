const ffi = require("ffi-rs"); // make sure to install this

const libPath = "../lib/libmylib.so";

ffi.open({
	library: "thelib",
	path: libPath
});

const lib = ffi.define({
	add: {
		library: "thelib",
		retType: ffi.DataType.I32,
		paramsType: [ffi.DataType.I32, ffi.DataType.I32],
	}
});

console.log(lib.add([6,2]));
