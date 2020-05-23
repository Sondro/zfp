// const handle to a 2D array or view element; this class is nested within container_type
class const_handle {
public:
  typedef typename container_type::value_type value_type;

protected:
  // protected constructor
  explicit const_handle(container_type* container, size_t i, size_t j) : container(container), i(i), j(j) {}

  // derefence handle
  value_type get() const { return container->get(i, j); }

  container_type* container; // container
  size_t i, j;               // element index
};

// reference to a 2D array or view element; this class is nested within container_type
class handle : public const_handle {
protected:
  // protected constructor
  explicit handle(container_type* container, size_t i, size_t j) : const_handle(container, i, j) {}

  // assign value through handle
  void set(value_type val) { container->set(i, j, val); }

  using const_handle::container;
  using const_handle::i;
  using const_handle::j;
};