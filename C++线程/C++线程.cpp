#include<iostream>
#include<thread>

static bool s_finished = false;

void Dowork()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id:" << std::this_thread::get_id() << std::endl;//获取id

	while (!s_finished)
	{
		std::cout << "Working...." << std::endl;
		std::this_thread::sleep_for(1s);
	}

}
int main()
{
	std::thread work(Dowork); //thread 用于创建和管理线程的类

	std::cin.get();         //在这里添加操作实现在打印working的时候一直检查用户有没有输入enter键
	                        //倘若这里没有加入任何操作 仅仅是看起来像串行实际还是并行 只是主线程在等待期间没有工作要做
	s_finished = true;

	work.join();//堵塞主线程，确保子线程(Dowork)完成后才进行主线程的后续操作

	std::cout << "Finished!" << std::endl;

	std::cout << "Finished thread id:" << std::this_thread::get_id() << std::endl;

	std::cin.get();
}