/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
         var count=0;
    var temp=0;
    return function () {
        if(count===0){
            count+=1
            temp=n
            return n
        }
        else{
            temp+=1
            return temp
        }
    }
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */