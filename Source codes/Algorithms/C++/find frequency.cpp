//returns a map with ele as key and its frequency as value.
map<int,int> findFrequency(vector<int> &v){
  map<int,int> m;
  for(int i=0;i<v.size();i++){
    m[v[i]]++;
  }
  return m;
}
