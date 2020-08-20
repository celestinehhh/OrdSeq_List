#include "OrdSeqList.h"	// 顺序表类

int main(void)
{
	char c = '*',l='*';
    OrdSeqList<int> la(6);
    OrdSeqList<int> lb(6);
    OrdSeqList<int> lc(12);
    int e, i, s, t;
    Status sta;

    while(l!='e'){
    c = '*';
    cout << "a:进入表a"<<endl;
    cout << "b:进入表b"<<endl;
    cout << "c:进入表c，表c用于存放表a和表b的合并表，仅可查看，不可操作"<<endl;
    cout << "e:退出"<<endl;
    cin  >> l;

    if(l=='a'){
    while (c != '0')
	{
        cout << endl << "表a";
        cout << endl << "1. 生成线性表.";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 取指定元素.";
        cout << endl << "4. 合并表a和表b.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 插入元素.";
        cout << endl << "7. 元素定位.";
        cout << endl << "8. 求线性表长度.";
        cout << endl << "9. 删除s和t之间的元素.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~8):";
		cin >> c;
		switch (c) 	{
			case '1':
			    la.Clear();
			    sta = SUCCESS;
				cout << endl << "输入e(e = 0时退出):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = la.InsertElem(e);
					if (sta == OVER_FLOW)
						cout << "线性表已满." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> i;
			    if (la.GetElem(i, e) == NOT_PRESENT)
					cout << "元素不存储." << endl;
				else
					cout << "元素:" << e << endl;
			    break;
			case '4':
			    lc=OrdSeqList<int> (la, lb);
			    cout << "表a和表b已合并入表C";
			    break;
			case '5':
			    cout << "被删除元素值:" << endl;
			    cin >> e;

			    if (la.DeleteElem(e) == RANGE_ERROR)
					cout << "没有该元素" << endl;
				else
                    cout << "成功" << endl;

			    break;

			case '6':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    sta = la.InsertElem(e);

			    if (sta == RANGE_ERROR)
					cout << "位置范围错." << endl;
				else if (sta == OVER_FLOW)
					cout << "线性表已满." << endl;
				else
					cout << "插入成功." << endl;
			    break;
			case '7':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    i = la.LocateElem(e);
			    if (i != 0)
					cout << "元素" << e << "的序号为：" << i << endl;
				else
					cout << "元素" << e << "不存在。"  << endl;
			    break;
			case '8':
			    cout << endl << "线性表的长度为:" << la.GetLength() << endl;
			    break;
            case '9':
			    cout << "请输入s和t(s<t)" << endl;
			    cout << "s:"<<endl;
			    cin >> s;
			    cout << "t:"<<endl;
			    cin >> t;
			    la.DeleteElemBetweenSandT(s,t);
			    break;
       	}
	}
    }

    if(l =='b'){
    while (c != '0')
	{
        cout << endl << "表b";
        cout << endl << "1. 生成线性表.";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 取指定元素.";
        cout << endl << "4. 合并表a和表b.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 插入元素.";
        cout << endl << "7. 元素定位.";
        cout << endl << "8. 求线性表长度.";
        cout << endl << "9. 删除s和t之间的元素.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~8):";
		cin >> c;
		switch (c) 	{
			case '1':
			    lb.Clear();
			    sta = SUCCESS;
				cout << endl << "输入e(e = 0时退出):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = lb.InsertElem(e);
					if (sta == OVER_FLOW)
						cout << "线性表已满." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    lb.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> i;
			    if (lb.GetElem(i, e) == NOT_PRESENT)
					cout << "元素不存储." << endl;
				else
					cout << "元素:" << e << endl;
			    break;
			case '4':
			    lc = OrdSeqList<int>(la,lb);
			    cout << "表a和表b已合并存放入表c";
			    break;
			case '5':
			    cout << "被删除元素值:" << endl;
			    cin >> e;

			    if (lb.DeleteElem(e) == RANGE_ERROR)
					cout << "没有该元素" << endl;
				else
                    cout << "成功" << endl;

			    break;

			case '6':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    sta = lb.InsertElem(e);

			    if (sta == RANGE_ERROR)
					cout << "位置范围错." << endl;
				else if (sta == OVER_FLOW)
					cout << "线性表已满." << endl;
				else
					cout << "插入成功." << endl;
			    break;
			case '7':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    i = lb.LocateElem(e);
			    if (i != 0)
					cout << "元素" << e << "的序号为：" << i << endl;
				else
					cout << "元素" << e << "不存在。"  << endl;
			    break;
			case '8':
			    cout << endl << "线性表的长度为:" << lb.GetLength() << endl;
			    break;
            case '9':
			    cout << "请输入s和t(s<t)" << endl;
			    cout << "s:"<<endl;
			    cin >> s;
			    cout << "t:"<<endl;
			    cin >> t;
			    lb.DeleteElemBetweenSandT(s,t);
			    break;
       	}
	}
    }
       if(l=='c'){
    while (c != '0')
	{
        cout << endl << "表c";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 取指定元素.";
        cout << endl << "7. 元素定位.";
        cout << endl << "8. 求线性表长度.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~8):";
		cin >> c;
		switch (c) 	{

			case '2':
			    lc.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> i;
			    if (lc.GetElem(i, e) == NOT_PRESENT)
					cout << "元素不存储." << endl;
				else
					cout << "元素:" << e << endl;
			    break;

			case '7':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    i = lc.LocateElem(e);
			    if (i != 0)
					cout << "元素" << e << "的序号为：" << i << endl;
				else
					cout << "元素" << e << "不存在。"  << endl;
			    break;
			case '8':
			    cout << endl << "线性表的长度为:" << lc.GetLength() << endl;
			    break;
       	}
	}
    }

    }

   	system("PAUSE");        		// 调用库函数system()，暂停程序运行
   	return 0;               		// 返回操作系统
}


