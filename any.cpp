template<typename T>
class field{
public:
  field();
  field(T&& data);
  template <class... Args>
  field(Args&& ...);
private:
  T data_;
};

template<typename T>
field::field() : data_(data) {}

template <class... Args>
field::field(Args&& ...){
  data_(Args ...);
}




class any {
public:
  // construction and destruction
  constexpr any() noexcept;
  any(const any& other);
  any(any&& other) noexcept;
  template <class ValueType> 
  any(ValueType&& value);
  template <class ValueType, class... Args>
  explicit any(in_place_type_t<ValueType>, Args&&...);
  template <class ValueType, class U, class... Args>
  explicit any(in_place_type_t<ValueType>, initializer_list<U>, Args&&...);
  ~any();
  // assignments
  any& operator=(const any& rhs);
  any& operator=(any&& rhs) noexcept;
  template <class ValueType> 
  any& operator=(ValueType&& rhs);
  // modifiers
  template <class ValueType, class... Args>
  void emplace(Args&& ...);
  template <class ValueType, class U, class... Args>
  void emplace(initializer_list<U>, Args&&...);
  void reset() noexcept;
  void swap(any& rhs) noexcept;
  // observers
  bool has_value() const noexcept;
  const type_info& type() const noexcept;

private:
  field *any_data;

};

template <class ValueType> 
any& any::operator=(ValueType&& rhs) : any_data(rhs){}

any& any::operator=(const any& rhs){
  any_data = ths.any_data;
}

any& any::operator=(any&& rhs) noexcept{
  any_data = std::move(ths.any_data);
}

template <class ValueType, class... Args>
void any::emplace(Args&& ...){
  any_data(Args ...);
}
