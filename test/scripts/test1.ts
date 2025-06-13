export function fun2c(a : string | number | boolean | undefined | Function | object | any[], b : boolean = false) : string | number | boolean | undefined {
    if (typeof a === "undefined") {
        return "undefined";
    } else if (typeof a === "number") {
        return a * 2;
    } else if (typeof a === "string") {
        return a.length;
    } else if (typeof a === "boolean") {
        return a;
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

console.log(fun2c(1, false));