
#include <iostream>
namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
	class list {
        public:
       	void		insert(int position, size_t n, const int& val) {
               std::cout << "No Temp" << std::endl;
		}
		template <class InputIterator>
		// static typename boost::enable_if<boost::is_convertible<InputIterator *, iterator *>,
		void		insert(int position, InputIterator first, InputIterator last) {
            std::cout << "With TEMP" << std::endl;
		} 
    };
} // namespace ft


int main()
{
    ft::list<int> x;

    x.insert(10, (size_t)1, 1);
    x.insert(10, "c", "a");
}