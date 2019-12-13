template<class T>
struct max_stack {
private:
  const T MINF = numeric_limits<T>::min(); // MENOS INFINITO
  stack<pair<T,T>> s; // Element, Max
public:
  void push(const T& x) {s.push(pair<T,T>(x,max(x,getmax())));}
  void pop() {s.pop();}
  bool empty() {return s.empty();}
  const T& getmax() {return empty() ? MINF : s.top().second;}
  const T& top() {return s.top().first;}};

template<class T>
struct max_queue {
private:
  max_stack<T> s1, s2;
  void transfer() {
    if (s1.empty()) {
      while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
    }
  }
public:
  void push(const T& x) {s2.push(x);}
  void pop() {transfer();s1.pop();}
  bool empty() {return s1.empty() && s2.empty();}
  const T& getmax() {return max(s1.getmax(), s2.getmax());}
  const T& front() {transfer(); return s1.top();}};
