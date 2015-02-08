#include <QCoreApplication>
#include<QVector>
#include<QList>
#include<QSet>
#include<QMap>
#include<QDebug>

void testVector();
void testList();
void test_set();
void testMap();


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

     testVector();
    // testList();
    // test_set();
    //testMap();

    return a.exec();
}

/**
 * @brief testVector
 */
void testVector(){
    QVector<int> vector;
    /**        增加      **/
    for(int i = 0;i< 10;i++){
       // vector.push_back(i);  //往后面添加
        //vector.push_front(i); //往前面添加
       // vector.insert(i,i);  //在位置i插入
       // vector.prepend(i);  //在最前面插入
        vector.append(i);  //往末尾追加

    }
   /**        查询        **/
    //1.遍历查询全部值
    foreach (int var,vector) {
        qDebug()<<var;
    }
    for(int i = 0;i< vector.size();i++){
        qDebug()<<vector.at(i);
    }
    for(QVector<int>::const_iterator it = vector.constBegin();it != vector.constEnd();it++){
        qDebug()<<*it;
    }
    //2.查询某个特定值是否存在
    qDebug()<<vector.contains(0);
    /**       改               **/
    //修改值
    vector[0] = 100;
    qDebug()<<vector.at(0);
    vector.replace(1,200);
    qDebug()<<vector.at(1);
    /**      删除                **/
    //删除
    vector.remove(0);
    qDebug()<<vector.at(0);

    /**  重新初始化为0，数量调整为7  **/
    vector.fill(0,7);
    qDebug()<<"size:::"<<vector.size();
    foreach (int var, vector) {
        qDebug()<<"::::::"<<var;
    }

    //全部删除
    for(QVector<int>::iterator it = vector.begin();it != vector.end();){
        QVector<int>::iterator temp = vector.erase(it);
        it = temp;
    }
    //vector.clear();
    qDebug()<<vector.size();

    /**    初始化  **/
    vector.fill(0,8);
    qDebug()<<"size:"<<vector.size();
    foreach (int var,vector) {
        qDebug()<<var;
    }
}

/**
 * @brief testList
 */
void testList(){
    QList<int> list;
    /**   增加         **/
    for(int i = 0;i<10;i++){
       // list.push_back(i);
        list.append(i);
       // list.push_front(i);
       // list.prepend(i);
       // list.insert(i,i);

    }
    /**        查询      **/
    //遍历
    foreach (int var,list) {
        qDebug()<<var;
    }
    //查询
    qDebug()<<list.contains(100);
    /**       删除         **/
    //删除
    qDebug()<<list.takeAt(0);
    list.removeAt(0);
    qDebug()<<list.removeOne(9);
    for(int i = 0;i<list.size();i++){
        qDebug()<<"::"<<list.at(i);
    }
    /**       修改       **/
    //修改
    list.replace(0,100);
    qDebug()<<list.first();

    /**      清空         **/
   //全部删除
   for(QList<int>::iterator it = list.begin();it != list.end();){
       it = list.erase(it);
   }
   qDebug()<<list.size();

}

/**
 * @brief testSet
 */
void test_set(){
    QSet<int> set;
    //插入
    for(int i = 0;i<10;i++){
        set.insert(i);
    }
    //遍历
    foreach (int var,set) {
        qDebug()<<var;
     }
    qDebug()<<*set.find(5);
    //删除
    qDebug()<<set.remove(8);
    //迭代遍历
    for(QSet<int>::iterator it = set.begin();it != set.end();it++){
        qDebug()<<*it;
    }
    //迭代清空
    for(QSet<int>::iterator it = set.begin();it != set.end();){
        it = set.erase(it);
    }
    qDebug()<<set.size();
}

/**
 * @brief testMap
 */
void testMap(){

    QMap<int,QString> map;
    for(int i = 0;i<10;i++){
        QString value = QString("value:%1").arg(i);
        map.insert(i,value);
    }
    map.insert(0,"00");
    qDebug()<<"&&&&&&&&&&&&&&&&&&&&&&&&&";
    //遍历查询
    for(int i = 0;i<map.size();i++){
        qDebug()<<map.value(i);
    }

    qDebug()<<"###########################";

    for( QMap<int,QString>::iterator it = map.begin();it != map.end();it++){
        qDebug()<<*it;
    }

    //还是不错的遍历方式
    QList<int> keys= map.keys();
    foreach (int key, keys) {
       qDebug()<<key<<":"<<map.value(key);
    }

    //查找
     if( map.find(0) != map.end()){
         qDebug()<<"is a value of map";
     }
     qDebug()<<map.contains(0);
     map.remove(0);
     qDebug()<<map.contains(0);

     for( QMap<int,QString>::iterator it = map.begin();it != map.end();){
         it = map.erase(it);
     }
     qDebug()<<map.size();
}
