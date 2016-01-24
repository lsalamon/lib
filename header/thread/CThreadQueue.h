#ifndef CTHREADQUEUE
#define CTHREADQUEUE
#include<condition_variable>
#include<cstddef>
#include<queue>
#include<mutex>

namespace nThread
{
	template<class T>
	class CThreadQueue
	{
	public:
		typedef T value_type;
		typedef typename std::queue<value_type>::size_type size_type;
	private:
		std::condition_variable push_;
		std::mutex pushMut_;
		std::queue<value_type> queue_;
	public:
		template<class ... Args>
		void emplace(Args &&...);
		inline size_type size() const noexcept
		{
			return queue_.size();
		}
		value_type wait_and_pop();
	};
}

#include"CThreadQueue.cpp"

#endif