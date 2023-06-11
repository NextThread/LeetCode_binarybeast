class SnapshotArray {
public:
    vector<vector<pair<int, int>>> m;
int cur_snap = 0;
SnapshotArray(int length) {
    m = vector<vector<pair<int, int>>>(length);
}
int snap() { return cur_snap++; }
void set(int index, int val) {
  if (m[index].empty() || m[index].back().first != cur_snap)
    m[index].push_back({ cur_snap, val });
  else m[index].back().second = val;
}
int get(int index, int snap_id) {
  auto it = upper_bound(begin(m[index]), end(m[index]), pair<int, int>(snap_id, INT_MAX));
  return it == begin(m[index]) ? 0 : prev(it)->second;
}};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */