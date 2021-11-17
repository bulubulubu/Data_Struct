

template<typename diverse>
class List_Sequence{
    private:
        diverse* Base_address; //基地址
        int Date_type_length;   //数据类型的长度
        int Used_length;    //已用长度
        int Total_length;   //总的长度
    public:
        //构造一个空的线性表
        List_Sequence();
        //销毁线性表
        ~List_Sequence();
        //重置线性表
        void ClearList();
        //判断线性表是不是空表，是空表返回ture，不是返回false
        bool ListEmpty();
        //返回线性表中的元素个数
        int ListLength();
        //返回线性表中第i个元素的值
        void GetElem(int i, diverse* e);
        //返回线性表中第一个与e满足关系compare()的数据元素的位序
        int LocateElem(diverse* e, void compare());
        //若e是线性表中的元素，且不是第一个，则返回他的前驱，否则返回0
        int PriorElem(diverse* e, diverse* pre_e);
        //若e是线性表中的元素，且不是最后一个，则返回他的后驱，否则返回0
        int NextElem(diverse* e, diverse* next_e);
        //在线性表的第i个位置之前插入新的数据元素e
        void ListInsert(int i, diverse *e);
        //删除线性表第i个位置的元素，并用e返回其值
        void ListDelete(int i, diverse* e);
        //依次对线性表的每个元素调用函数visit()，一但visit()失败，则操作失败
        void ListTraverse(void visit());
        //写入一个元素到线性表
        void WriteElem(diverse* e);
};