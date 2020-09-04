// Codeforces 1195E.
template<class T>
class MaxStack {
const T MINF = numeric_limits<T>::lowest(); // -INFINITO.
stack<pair<T,T>> s; // {Element, Max}.
public:
void push(const T& x) {s.push(pair<T,T>(x,max(x,getmax())));}
void pop() {s.pop();}
size_t size() const {return s.size();}
bool empty() const {return s.empty();}
const T& getmax() const {return empty() ? MINF : s.top().second;}
const T& top() const {return s.top().first;}};

template<class T>
class MaxQueue {
MaxStack<T> s1, s2;
void transfer() {
  if (!s1.empty()) return;
  while (!s2.empty()) s1.push(s2.top()), s2.pop();
}
public:
void push(const T& x) {s2.push(x);}
void pop() {transfer();s1.pop();}
size_t size() const {return s1.size()+s2.size();}
bool empty() const {return s1.empty() && s2.empty();}
const T& getmax() const {return max(s1.getmax(), s2.getmax());}
const T& front() {transfer(); return s1.top();}};
