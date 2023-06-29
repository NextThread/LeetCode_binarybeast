/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function (arr, size) {
let newArr = []
while (arr.length !== 0) {
    newArr = [...newArr, arr.splice(0, arr.length > size ? size : arr.length)]
}
return newArr;
}