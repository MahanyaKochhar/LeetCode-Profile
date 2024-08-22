/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let count = 0;
    return function() {
        let v = n + count;
        count += 1;
        return v;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
