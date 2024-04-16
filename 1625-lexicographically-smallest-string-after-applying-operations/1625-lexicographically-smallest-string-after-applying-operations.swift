class Solution {
    func findLexSmallestString(_ s: String, _ a: Int, _ b: Int) -> String {
    func change(_ st :[Character])->[Character]{
        var st = st
        for (i,ch) in st.enumerated(){
            if i % 2 == 1{
                let v = (Int(String(ch))! + a) % 10
                    st[i] = String(v).first!
            }
        }
        return st
    }
    func rotate(_ st : [Character])->[Character]{
        return Array(st[st.count-b..<st.count]) + Array(st[0..<st.count-b])
    }
    var set : Set<String> = [], arr : [String] = [s], mini = s
    while arr.count > 0{
        let x = arr.removeLast()
        if mini > x{
            mini = x
        }
        if !set.contains(x){
            set.insert(x)
            arr.append(String(change(Array(x))))
            arr.append(String(rotate(Array(x))))
        }
    }
    return mini
}
}