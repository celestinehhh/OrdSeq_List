#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include "Assistance.h"	// 辅助软件包

// 顺序表模板类的申明
template <class ElemType>
class OrdSeqList
{
protected:
// 顺序表的数据成员
	int length;					// 顺序表的当前长度
	int maxLength;				// 顺序表的最大容量
	ElemType *elems;			// 元素存储空间的首地址

public:
// 顺序表的函数成员
	OrdSeqList(int size = DEFAULT_SIZE);	// 构造一个空表
	OrdSeqList(ElemType v[], int n, int size = DEFAULT_SIZE);	// 根据数组v的内容构造顺序表
	virtual ~OrdSeqList();			// 析构函数
	int GetLength() const;		// 取顺序表长度
	bool IsEmpty() const;		// 判断顺序表是否为空
	void Clear();				// 将顺序表清空
	void Traverse(void (*Visit)(const ElemType &)) const;	// 遍历顺序表
	int LocateElem(const ElemType &e) const;	// 元素定位，求指定元素在顺序表中的位置
	Status GetElem(int i, ElemType &e) const;	// 取顺序表中第i个元素的值
	Status DeleteElem(ElemType &e);              // 删除值为e的元素
	Status DeleteElemBetweenSandT(ElemType s,ElemType t);
 	Status InsertElem(const ElemType &e);        // 在有序顺序表表中插入元素e，并且自动排序
	OrdSeqList(const OrdSeqList<ElemType> &sa);        // 复制构造函数
	OrdSeqList(const OrdSeqList<ElemType> &sa,const OrdSeqList<ElemType> &sb);    //合并构造函数
	OrdSeqList<ElemType> &operator =(const OrdSeqList<ElemType> &sa); // 赋值语句重载
};


// 顺序表函数成员的实现部分

template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(int size)
// 操作结果：构造一个最大容量为size的空顺序表
{
	elems = new ElemType[size];		    // 申请存储空间
	assert(elems);                      // 申请存储空间失败，程序终止
	maxLength = size;					// 设置顺序表的最大容量
	length = 0;							// 空线性表的长度为0
}

template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(ElemType v[], int n, int size)
// 操作结果：根据数组v中的内容构造顺序表
{
	elems = new ElemType[size];		    // 申请存储空间
	assert(elems);                      // 申请存储空间失败，程序终止
	maxLength = size;					// 设置顺序表的最大容量
	length = n;
	elems[0]=v[0];						// 顺序表的当前长度为n
	for (int i = 1; i < length; i++)	// 将数组v中的元素依次存放到elems数组中
		InsertElem(v[i]);
}

template <class ElemType>
OrdSeqList<ElemType>::~OrdSeqList()
// 功能：回收顺序表的存储空间
{
	delete []elems;						// 释放存储空间
}

template <class ElemType>
int OrdSeqList<ElemType>::GetLength() const
// 功能：返回顺序表中元素个数
{
	return length;
}

template <class ElemType>
bool OrdSeqList<ElemType>::IsEmpty() const
// 功能：如顺序表为空，则返回true，否则返回false
{
	return length == 0;
}

template <class ElemType>
void OrdSeqList<ElemType>::Clear()
// 功能：清空顺序表
{
	length = 0;
}

template <class ElemType>
void OrdSeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
// 功能：依次对顺序表的每个元素调用函数(*visit)进行访问
{
	for (int i = 0; i < length; i++)
		(*visit)(elems[i]);
}

template <class ElemType>
int OrdSeqList<ElemType>::LocateElem(const ElemType &e) const
// 功能：求元素e在顺序表中的序号,如果顺序表中不存在元素e则返回0
{
	int i = 0;
    while (i < length && elems[i] != e)
         i++;
    return i < length ? i+1 : 0;
}

template <class ElemType>
Status OrdSeqList<ElemType>::GetElem(int i, ElemType &e) const
// 功能：当顺序表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,否则函数返回NOT_PRESENT
{
	if(i < 1 || i > length)
		return NOT_PRESENT;	// 返回元素不存在
	else	{
		e = elems[i - 1];
		return ENTRY_FOUND;	// 元素存在
	}
}



template <class ElemType>
Status OrdSeqList<ElemType>::DeleteElem(ElemType &e)
// 功能：删除顺序表第i个位置的元素, 并前用e返回其值。i的的取值范围为1≤i≤length,i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	int i = 0, j;
	while (i <= length -1 && elems[i]<e)   //找出第一个等于e的元素i
        i++;
    if(i <= length-1 && elems [i] == e){  // 确保第一个元素是e即元素e存在
        j = i+1;
        while(j <= length - 1 && elems[j] == e)//找到第一个不等于e的元素
            j++;
        while(j <= length ){
            elems[i++] = elems[j++];     //将elems[j]开始的元素逐个前移到elems[i]后的位置，直到最后一个
            }

        length = length + i - j;        //将已删除的元素个数（j-i）从长度里删除
    }
    else{return RANGE_ERROR;}
    return SUCCESS;

}



template <class ElemType>
Status OrdSeqList<ElemType>::InsertElem(const ElemType &e)
// 功能：将元素e插到适当位置，保证从小到大顺序不变并则返回SUCCESS，如顺序表已满,则返回OVER_FLOW
{
	int i = length;
	if (length==maxLength)		// 顺序表已满返回OVER_FLOW
		return OVER_FLOW;
	else	{

		while(i>0&&elems[i-1]>e){        // 从最后一个元素开始，比较e与前一个元素的值
                elems[i]=elems[i-1];     //若前一个元素的值比e大，则前一个元素后移
                i--;                     //e前移
            }
            elems[i] = e;
    		length++;				// 插入后，顺序表元素个数加1
     	return SUCCESS;			// 返回插入成功
	}
}

template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(const OrdSeqList<ElemType> &sa)
// 功能：复制构造函数，由顺序表sa构造新顺序表
{
	int saLength = sa.GetLength();	// 取顺序表sa的长度
	ElemType e;

	maxLength = sa.maxLength;		// 取顺序表的最大容量
	elems = new ElemType[maxLength];// 分配存储空间
	assert(elems);                  // 分配存储空间失败
	length = 0;					    // 空顺序表元素个数为0

	for (int i = 1; i <= saLength; i++)	{
		sa.getElem(i, e);		    // 取出顺序表sa中第i个元素
		insertElem(e);			    // 将e插入到当前顺序表的表尾
	}
}


template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(const OrdSeqList<ElemType> &sa, const OrdSeqList<ElemType> &sb)
 //合并表sa和表sb成为新表，新表依旧按照顺序排列
{
    int saLength = sa.GetLength();
    int sbLength = sb.GetLength();

    ElemType e1, e2;

    if(sa.maxLength > sb.maxLength)
        maxLength = 2 * sa.maxLength;
    else
        maxLength = 2 * sb.maxLength;

    elems = new ElemType[maxLength];
    assert(elems);


    length = 0;
    int i = 1,j = 1;
    sa.GetElem(1, e1);
    sb.GetElem(1, e2);
    //cout<<"e1:"<<e1<<endl;
    //cout<<"e2:"<<e2<<endl;

    while(i<= saLength && j<= sbLength){
        if(e1 < e2){
            elems[length++] = e1;
            //cout<<e1<<endl;
            sa.GetElem(++i, e1);
        }
        else{
            elems[length++] = e2;
            //cout<<e2<<endl;
            sb.GetElem(++j, e2);
        }
    }

    while(i <= saLength){      //表sa的最大值比sb大，还有剩余值，添加入新表
        elems[length++] = e1;
        sa.GetElem(++i, e1);
    }

    while(j <= sbLength){     //表sb的最大值比sa大，还有剩余值，添加入新表
        elems[length++] = e2;
        sa.GetElem(++j, e2);
    }

//cout<<"ok1"<<endl;

}


template <class ElemType>
OrdSeqList<ElemType> &OrdSeqList<ElemType>::operator =(const OrdSeqList<ElemType> &sa)
// 功能：赋值语句重载，将顺序表sa赋值给当前顺序表
{
//cout<<"enter"<<endl;
	if (&sa != this)	{
		int saLength = sa.GetLength();	// 取顺序表sa的长度
		ElemType e;

        maxLength = sa.maxLength;		// 取顺序表的最大容量
        delete []elems;                 // 释放顺序表原来的存储空间
        elems = new ElemType[maxLength];// 分配存储空间
	    assert(elems);                  // 分配存储空间失败
        length = 0;						// 空顺序表元素个数为0
        for (int i = 1; i <= saLength; i++)	{
			sa.GetElem(i, e);	        // 取出顺序表sa中第i个元素
			InsertElem(e);		            // 将e插入到当前顺序表的表尾
		}
	}
	//cout<< "ok2";
	return *this;
}

template <class ElemType>
Status OrdSeqList<ElemType>::DeleteElemBetweenSandT(ElemType s,ElemType t)
//删除s和t之间的元素
{
    int i = 0, j;
    if(length <= 0 || s > t ){
        cout << "空列表或数据不合法";
        return RANGE_ERROR;
    }
    else{
        while(i <= length - 1 && elems[i] < s) //找到第一个大于等于s的元素elems[i]
            i++;
        if(elems [i] < t){  // 如果s和t之间没有元素，则直接结束程序
            j = i+1;        // j是elems[i]后的第一个元素elems[j]
            while(j <= length - 1 && elems [j] < t )//找到第一个大于等于t的元素elems[j]
                j++;
            while(j <= length){
                elems[i++]=elems[j++];//将elems[j]开始的元素逐个前移到elems[i]后的位置，直到最后一个
            }
            length = length + i - j;//将已删除的元素个数（j-i）从长度里删除
        }

    }
    return SUCCESS;
}

#endif
