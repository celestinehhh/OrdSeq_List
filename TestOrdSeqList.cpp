#include "OrdSeqList.h"	// ˳�����

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
    cout << "a:�����a"<<endl;
    cout << "b:�����b"<<endl;
    cout << "c:�����c����c���ڴ�ű�a�ͱ�b�ĺϲ������ɲ鿴�����ɲ���"<<endl;
    cout << "e:�˳�"<<endl;
    cin  >> l;

    if(l=='a'){
    while (c != '0')
	{
        cout << endl << "��a";
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��.";
        cout << endl << "4. �ϲ���a�ͱ�b.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
        cout << endl << "8. �����Ա���.";
        cout << endl << "9. ɾ��s��t֮���Ԫ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~8):";
		cin >> c;
		switch (c) 	{
			case '1':
			    la.Clear();
			    sta = SUCCESS;
				cout << endl << "����e(e = 0ʱ�˳�):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = la.InsertElem(e);
					if (sta == OVER_FLOW)
						cout << "���Ա�����." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> i;
			    if (la.GetElem(i, e) == NOT_PRESENT)
					cout << "Ԫ�ز��洢." << endl;
				else
					cout << "Ԫ��:" << e << endl;
			    break;
			case '4':
			    lc=OrdSeqList<int> (la, lb);
			    cout << "��a�ͱ�b�Ѻϲ����C";
			    break;
			case '5':
			    cout << "��ɾ��Ԫ��ֵ:" << endl;
			    cin >> e;

			    if (la.DeleteElem(e) == RANGE_ERROR)
					cout << "û�и�Ԫ��" << endl;
				else
                    cout << "�ɹ�" << endl;

			    break;

			case '6':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    sta = la.InsertElem(e);

			    if (sta == RANGE_ERROR)
					cout << "λ�÷�Χ��." << endl;
				else if (sta == OVER_FLOW)
					cout << "���Ա�����." << endl;
				else
					cout << "����ɹ�." << endl;
			    break;
			case '7':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    i = la.LocateElem(e);
			    if (i != 0)
					cout << "Ԫ��" << e << "�����Ϊ��" << i << endl;
				else
					cout << "Ԫ��" << e << "�����ڡ�"  << endl;
			    break;
			case '8':
			    cout << endl << "���Ա�ĳ���Ϊ:" << la.GetLength() << endl;
			    break;
            case '9':
			    cout << "������s��t(s<t)" << endl;
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
        cout << endl << "��b";
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��.";
        cout << endl << "4. �ϲ���a�ͱ�b.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
        cout << endl << "8. �����Ա���.";
        cout << endl << "9. ɾ��s��t֮���Ԫ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~8):";
		cin >> c;
		switch (c) 	{
			case '1':
			    lb.Clear();
			    sta = SUCCESS;
				cout << endl << "����e(e = 0ʱ�˳�):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = lb.InsertElem(e);
					if (sta == OVER_FLOW)
						cout << "���Ա�����." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    lb.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> i;
			    if (lb.GetElem(i, e) == NOT_PRESENT)
					cout << "Ԫ�ز��洢." << endl;
				else
					cout << "Ԫ��:" << e << endl;
			    break;
			case '4':
			    lc = OrdSeqList<int>(la,lb);
			    cout << "��a�ͱ�b�Ѻϲ�������c";
			    break;
			case '5':
			    cout << "��ɾ��Ԫ��ֵ:" << endl;
			    cin >> e;

			    if (lb.DeleteElem(e) == RANGE_ERROR)
					cout << "û�и�Ԫ��" << endl;
				else
                    cout << "�ɹ�" << endl;

			    break;

			case '6':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    sta = lb.InsertElem(e);

			    if (sta == RANGE_ERROR)
					cout << "λ�÷�Χ��." << endl;
				else if (sta == OVER_FLOW)
					cout << "���Ա�����." << endl;
				else
					cout << "����ɹ�." << endl;
			    break;
			case '7':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    i = lb.LocateElem(e);
			    if (i != 0)
					cout << "Ԫ��" << e << "�����Ϊ��" << i << endl;
				else
					cout << "Ԫ��" << e << "�����ڡ�"  << endl;
			    break;
			case '8':
			    cout << endl << "���Ա�ĳ���Ϊ:" << lb.GetLength() << endl;
			    break;
            case '9':
			    cout << "������s��t(s<t)" << endl;
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
        cout << endl << "��c";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
        cout << endl << "8. �����Ա���.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~8):";
		cin >> c;
		switch (c) 	{

			case '2':
			    lc.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> i;
			    if (lc.GetElem(i, e) == NOT_PRESENT)
					cout << "Ԫ�ز��洢." << endl;
				else
					cout << "Ԫ��:" << e << endl;
			    break;

			case '7':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    i = lc.LocateElem(e);
			    if (i != 0)
					cout << "Ԫ��" << e << "�����Ϊ��" << i << endl;
				else
					cout << "Ԫ��" << e << "�����ڡ�"  << endl;
			    break;
			case '8':
			    cout << endl << "���Ա�ĳ���Ϊ:" << lc.GetLength() << endl;
			    break;
       	}
	}
    }

    }

   	system("PAUSE");        		// ���ÿ⺯��system()����ͣ��������
   	return 0;               		// ���ز���ϵͳ
}


