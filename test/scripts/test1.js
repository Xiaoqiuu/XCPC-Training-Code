function func(a) {
    if (typeof a === "undefined") {
        return "undefined";
    } else if (typeof a === "number") {
        return {
            type: "number",
            value: a
        };
    } else if (typeof a === "string") {
        return ["string", a];
    } else if (typeof a === "boolean") {
        return func;
    } else if (typeof a === "function") {
        return "function";
    } else if (typeof a === "object") {
        if (Array.isArray(a)) {
            return "array";
        } else {
            return "object";
        }
    } else {
        return "unknown";
    }
}

console.log(func());