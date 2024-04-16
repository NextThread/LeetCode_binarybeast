# @param {String} word
# @return {Integer}
def minimum_pushes(word)
    a = [ [], [], [], [], [], [], [], [] ]
    h = word.chars.tally.sort_by { |k, v| v }.reverse.to_h
    press = i = 0
    h.keys.each do |ch|
        a[i] << ch
        press += a[i].count * h[ch]
        i += 1
        i %= 8
    end
    press
end