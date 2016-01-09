#ifndef CTHREADLIST
#define CTHREADLIST
#include<condition_variable>
#include<cstddef>
#include<list>
#include<mutex>

namespace nThread
{
	template<class T>
	class CThreadList
	{
		std::condition_variable insert_;
		std::mutex insertMut_;
		std::list<T> list_;
	public:
		template<class ... Args>
		void emplace_back(Args &&...);
		template<class UnaryPred>
		void remove_if(UnaryPred);
		inline std::size_t size() const noexcept
		{
			return list_.size();
		}
		T wait_and_pop();
	};
}

#include"CThreadList.cpp"

#endif