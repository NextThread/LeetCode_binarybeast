/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let map={},arrs=[...arr1,...arr2].map((e)=> map[e.id]={...map[e.id],...e})
    return [...Object.values(map)]   
};