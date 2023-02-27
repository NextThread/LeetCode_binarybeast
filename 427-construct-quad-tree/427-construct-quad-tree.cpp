class Solution {
public:
  Node* construct(vector<vector<int>>& grid) {
    grid_ = move(grid);
    leafNodes_[0] = new Node(false, true, nullptr, nullptr, nullptr, nullptr);
    leafNodes_[1] = new Node(true,  true, nullptr, nullptr, nullptr, nullptr);
    return construct(0, 0, grid_.size());
  }
  
  Node* construct(int r, int c, int s) {
    if (s == 1)
      return leafNodes_[grid_[r][c]];
    s /= 2;
    Node* tl = construct(r,   c,   s);
    Node* tr = construct(r,   c+s, s);
    Node* bl = construct(r+s, c,   s);
    Node* br = construct(r+s, c+s, s);
    if (tl == tr && tl == bl && tl == br)
      return tl;
    return new Node(false, false, tl, tr, bl, br);
  }
  
private:
  vector<vector<int>> grid_;
  array<Node*, 2> leafNodes_;
};