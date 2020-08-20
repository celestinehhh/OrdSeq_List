#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include "Assistance.h"	// ���������

// ˳���ģ���������
template <class ElemType>
class OrdSeqList
{
protected:
// ˳�������ݳ�Ա
	int length;					// ˳���ĵ�ǰ����
	int maxLength;				// ˳�����������
	ElemType *elems;			// Ԫ�ش洢�ռ���׵�ַ

public:
// ˳���ĺ�����Ա
	OrdSeqList(int size = DEFAULT_SIZE);	// ����һ���ձ�
	OrdSeqList(ElemType v[], int n, int size = DEFAULT_SIZE);	// ��������v�����ݹ���˳���
	virtual ~OrdSeqList();			// ��������
	int GetLength() const;		// ȡ˳�����
	bool IsEmpty() const;		// �ж�˳����Ƿ�Ϊ��
	void Clear();				// ��˳������
	void Traverse(void (*Visit)(const ElemType &)) const;	// ����˳���
	int LocateElem(const ElemType &e) const;	// Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��
	Status GetElem(int i, ElemType &e) const;	// ȡ˳����е�i��Ԫ�ص�ֵ
	Status DeleteElem(ElemType &e);              // ɾ��ֵΪe��Ԫ��
	Status DeleteElemBetweenSandT(ElemType s,ElemType t);
 	Status InsertElem(const ElemType &e);        // ������˳�����в���Ԫ��e�������Զ�����
	OrdSeqList(const OrdSeqList<ElemType> &sa);        // ���ƹ��캯��
	OrdSeqList(const OrdSeqList<ElemType> &sa,const OrdSeqList<ElemType> &sb);    //�ϲ����캯��
	OrdSeqList<ElemType> &operator =(const OrdSeqList<ElemType> &sa); // ��ֵ�������
};


// ˳�������Ա��ʵ�ֲ���

template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(int size)
// �������������һ���������Ϊsize�Ŀ�˳���
{
	elems = new ElemType[size];		    // ����洢�ռ�
	assert(elems);                      // ����洢�ռ�ʧ�ܣ�������ֹ
	maxLength = size;					// ����˳�����������
	length = 0;							// �����Ա�ĳ���Ϊ0
}

template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(ElemType v[], int n, int size)
// �����������������v�е����ݹ���˳���
{
	elems = new ElemType[size];		    // ����洢�ռ�
	assert(elems);                      // ����洢�ռ�ʧ�ܣ�������ֹ
	maxLength = size;					// ����˳�����������
	length = n;
	elems[0]=v[0];						// ˳���ĵ�ǰ����Ϊn
	for (int i = 1; i < length; i++)	// ������v�е�Ԫ�����δ�ŵ�elems������
		InsertElem(v[i]);
}

template <class ElemType>
OrdSeqList<ElemType>::~OrdSeqList()
// ���ܣ�����˳���Ĵ洢�ռ�
{
	delete []elems;						// �ͷŴ洢�ռ�
}

template <class ElemType>
int OrdSeqList<ElemType>::GetLength() const
// ���ܣ�����˳�����Ԫ�ظ���
{
	return length;
}

template <class ElemType>
bool OrdSeqList<ElemType>::IsEmpty() const
// ���ܣ���˳���Ϊ�գ��򷵻�true�����򷵻�false
{
	return length == 0;
}

template <class ElemType>
void OrdSeqList<ElemType>::Clear()
// ���ܣ����˳���
{
	length = 0;
}

template <class ElemType>
void OrdSeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
// ���ܣ����ζ�˳����ÿ��Ԫ�ص��ú���(*visit)���з���
{
	for (int i = 0; i < length; i++)
		(*visit)(elems[i]);
}

template <class ElemType>
int OrdSeqList<ElemType>::LocateElem(const ElemType &e) const
// ���ܣ���Ԫ��e��˳����е����,���˳����в�����Ԫ��e�򷵻�0
{
	int i = 0;
    while (i < length && elems[i] != e)
         i++;
    return i < length ? i+1 : 0;
}

template <class ElemType>
Status OrdSeqList<ElemType>::GetElem(int i, ElemType &e) const
// ���ܣ���˳�����ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,����������NOT_PRESENT
{
	if(i < 1 || i > length)
		return NOT_PRESENT;	// ����Ԫ�ز�����
	else	{
		e = elems[i - 1];
		return ENTRY_FOUND;	// Ԫ�ش���
	}
}



template <class ElemType>
Status OrdSeqList<ElemType>::DeleteElem(ElemType &e)
// ���ܣ�ɾ��˳����i��λ�õ�Ԫ��, ��ǰ��e������ֵ��i�ĵ�ȡֵ��ΧΪ1��i��length,i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	int i = 0, j;
	while (i <= length -1 && elems[i]<e)   //�ҳ���һ������e��Ԫ��i
        i++;
    if(i <= length-1 && elems [i] == e){  // ȷ����һ��Ԫ����e��Ԫ��e����
        j = i+1;
        while(j <= length - 1 && elems[j] == e)//�ҵ���һ��������e��Ԫ��
            j++;
        while(j <= length ){
            elems[i++] = elems[j++];     //��elems[j]��ʼ��Ԫ�����ǰ�Ƶ�elems[i]���λ�ã�ֱ�����һ��
            }

        length = length + i - j;        //����ɾ����Ԫ�ظ�����j-i���ӳ�����ɾ��
    }
    else{return RANGE_ERROR;}
    return SUCCESS;

}



template <class ElemType>
Status OrdSeqList<ElemType>::InsertElem(const ElemType &e)
// ���ܣ���Ԫ��e�嵽�ʵ�λ�ã���֤��С����˳�򲻱䲢�򷵻�SUCCESS����˳�������,�򷵻�OVER_FLOW
{
	int i = length;
	if (length==maxLength)		// ˳�����������OVER_FLOW
		return OVER_FLOW;
	else	{

		while(i>0&&elems[i-1]>e){        // �����һ��Ԫ�ؿ�ʼ���Ƚ�e��ǰһ��Ԫ�ص�ֵ
                elems[i]=elems[i-1];     //��ǰһ��Ԫ�ص�ֵ��e����ǰһ��Ԫ�غ���
                i--;                     //eǰ��
            }
            elems[i] = e;
    		length++;				// �����˳���Ԫ�ظ�����1
     	return SUCCESS;			// ���ز���ɹ�
	}
}

template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(const OrdSeqList<ElemType> &sa)
// ���ܣ����ƹ��캯������˳���sa������˳���
{
	int saLength = sa.GetLength();	// ȡ˳���sa�ĳ���
	ElemType e;

	maxLength = sa.maxLength;		// ȡ˳�����������
	elems = new ElemType[maxLength];// ����洢�ռ�
	assert(elems);                  // ����洢�ռ�ʧ��
	length = 0;					    // ��˳���Ԫ�ظ���Ϊ0

	for (int i = 1; i <= saLength; i++)	{
		sa.getElem(i, e);		    // ȡ��˳���sa�е�i��Ԫ��
		insertElem(e);			    // ��e���뵽��ǰ˳���ı�β
	}
}


template <class ElemType>
OrdSeqList<ElemType>::OrdSeqList(const OrdSeqList<ElemType> &sa, const OrdSeqList<ElemType> &sb)
 //�ϲ���sa�ͱ�sb��Ϊ�±��±����ɰ���˳������
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

    while(i <= saLength){      //��sa�����ֵ��sb�󣬻���ʣ��ֵ��������±�
        elems[length++] = e1;
        sa.GetElem(++i, e1);
    }

    while(j <= sbLength){     //��sb�����ֵ��sa�󣬻���ʣ��ֵ��������±�
        elems[length++] = e2;
        sa.GetElem(++j, e2);
    }

//cout<<"ok1"<<endl;

}


template <class ElemType>
OrdSeqList<ElemType> &OrdSeqList<ElemType>::operator =(const OrdSeqList<ElemType> &sa)
// ���ܣ���ֵ������أ���˳���sa��ֵ����ǰ˳���
{
//cout<<"enter"<<endl;
	if (&sa != this)	{
		int saLength = sa.GetLength();	// ȡ˳���sa�ĳ���
		ElemType e;

        maxLength = sa.maxLength;		// ȡ˳�����������
        delete []elems;                 // �ͷ�˳���ԭ���Ĵ洢�ռ�
        elems = new ElemType[maxLength];// ����洢�ռ�
	    assert(elems);                  // ����洢�ռ�ʧ��
        length = 0;						// ��˳���Ԫ�ظ���Ϊ0
        for (int i = 1; i <= saLength; i++)	{
			sa.GetElem(i, e);	        // ȡ��˳���sa�е�i��Ԫ��
			InsertElem(e);		            // ��e���뵽��ǰ˳���ı�β
		}
	}
	//cout<< "ok2";
	return *this;
}

template <class ElemType>
Status OrdSeqList<ElemType>::DeleteElemBetweenSandT(ElemType s,ElemType t)
//ɾ��s��t֮���Ԫ��
{
    int i = 0, j;
    if(length <= 0 || s > t ){
        cout << "���б�����ݲ��Ϸ�";
        return RANGE_ERROR;
    }
    else{
        while(i <= length - 1 && elems[i] < s) //�ҵ���һ�����ڵ���s��Ԫ��elems[i]
            i++;
        if(elems [i] < t){  // ���s��t֮��û��Ԫ�أ���ֱ�ӽ�������
            j = i+1;        // j��elems[i]��ĵ�һ��Ԫ��elems[j]
            while(j <= length - 1 && elems [j] < t )//�ҵ���һ�����ڵ���t��Ԫ��elems[j]
                j++;
            while(j <= length){
                elems[i++]=elems[j++];//��elems[j]��ʼ��Ԫ�����ǰ�Ƶ�elems[i]���λ�ã�ֱ�����һ��
            }
            length = length + i - j;//����ɾ����Ԫ�ظ�����j-i���ӳ�����ɾ��
        }

    }
    return SUCCESS;
}

#endif
