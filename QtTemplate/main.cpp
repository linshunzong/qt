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
    /**        ����      **/
    for(int i = 0;i< 10;i++){
       // vector.push_back(i);  //���������
        //vector.push_front(i); //��ǰ�����
       // vector.insert(i,i);  //��λ��i����
       // vector.prepend(i);  //����ǰ�����
        vector.append(i);  //��ĩβ׷��

    }
   /**        ��ѯ        **/
    //1.������ѯȫ��ֵ
    foreach (int var,vector) {
        qDebug()<<var;
    }
    for(int i = 0;i< vector.size();i++){
        qDebug()<<vector.at(i);
    }
    for(QVector<int>::const_iterator it = vector.constBegin();it != vector.constEnd();it++){
        qDebug()<<*it;
    }
    //2.��ѯĳ���ض�ֵ�Ƿ����
    qDebug()<<vector.contains(0);
    /**       ��               **/
    //�޸�ֵ
    vector[0] = 100;
    qDebug()<<vector.at(0);
    vector.replace(1,200);
    qDebug()<<vector.at(1);
    /**      ɾ��                **/
    //ɾ��
    vector.remove(0);
    qDebug()<<vector.at(0);

    /**  ���³�ʼ��Ϊ0����������Ϊ7  **/
    vector.fill(0,7);
    qDebug()<<"size:::"<<vector.size();
    foreach (int var, vector) {
        qDebug()<<"::::::"<<var;
    }

    //ȫ��ɾ��
    for(QVector<int>::iterator it = vector.begin();it != vector.end();){
        QVector<int>::iterator temp = vector.erase(it);
        it = temp;
    }
    //vector.clear();
    qDebug()<<vector.size();

    /**    ��ʼ��  **/
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
    /**   ����         **/
    for(int i = 0;i<10;i++){
       // list.push_back(i);
        list.append(i);
       // list.push_front(i);
       // list.prepend(i);
       // list.insert(i,i);

    }
    /**        ��ѯ      **/
    //����
    foreach (int var,list) {
        qDebug()<<var;
    }
    //��ѯ
    qDebug()<<list.contains(100);
    /**       ɾ��         **/
    //ɾ��
    qDebug()<<list.takeAt(0);
    list.removeAt(0);
    qDebug()<<list.removeOne(9);
    for(int i = 0;i<list.size();i++){
        qDebug()<<"::"<<list.at(i);
    }
    /**       �޸�       **/
    //�޸�
    list.replace(0,100);
    qDebug()<<list.first();

    /**      ���         **/
   //ȫ��ɾ��
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
    //����
    for(int i = 0;i<10;i++){
        set.insert(i);
    }
    //����
    foreach (int var,set) {
        qDebug()<<var;
     }
    qDebug()<<*set.find(5);
    //ɾ��
    qDebug()<<set.remove(8);
    //��������
    for(QSet<int>::iterator it = set.begin();it != set.end();it++){
        qDebug()<<*it;
    }
    //�������
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
    //������ѯ
    for(int i = 0;i<map.size();i++){
        qDebug()<<map.value(i);
    }

    qDebug()<<"###########################";

    for( QMap<int,QString>::iterator it = map.begin();it != map.end();it++){
        qDebug()<<*it;
    }

    //���ǲ���ı�����ʽ
    QList<int> keys= map.keys();
    foreach (int key, keys) {
       qDebug()<<key<<":"<<map.value(key);
    }

    //����
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
