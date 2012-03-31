/*
 * kpSDK��һ�����ڽ�ɽ���̺�Qt������sdk�⣬���������ɷַ����޸����е�Դ����������·�������
 * �µ��κ��޸ĺ�����·��������ͬ��������LGPL3��������İ汾Э���·���.
 * ����LGPLЭ���ϸ����ο�COPYING��COPYING.LESSER�ļ���
 * ��������kpSDK\examples\qtdll�����Ŀ¼�л��LGPLЭ��ĸ�����
 * ���û���ҵ��������ӵ� http://www.gnu.org/licenses/ �鿴��
*/
//kuaipan cpp sdk for windows
//Email: michael.20@qq.com
//License: GNU Lesser General Public License (LGPL)
//��Ȩ���� (C) 2012 Michael Lee

#ifndef KPSDK_H
#define KPSDK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTextCodec>
#include <QWebFrame>
#include <QFile>
#include <QEventLoop>
#include "publicFun.h"

typedef struct _auTokenJson
{
    QString auToken;
    QString auTokenSecret;
    QString usrID;
    QString chargedDir;
    QString mUploadNode;
}struAuToken;

typedef struct _usrInfoJson
{
    QString maxFileSize;
    QString quotaTotal;
    QString quotaUsed;
    QString usrName;

}struUsrInfo;

class kpSDK : public QObject
{
    Q_OBJECT
public:
    explicit kpSDK(QObject *parent = 0);
    ~kpSDK();
    void    reqReqTmpToken();
    void    reqAcessToken();
    void    reqUsrInfo();
    void    reqMetaData();
    void    reqCreateFloder();
    void    reqDelFile();
    void    reqMoveFile();
    void    reqCopyFile();
    void    reqUploadLocate();
    void    reqUploadFile();
    void    reqDownLoadFile();
    void    reqShareFile();
    bool    mIsAppPath;
    bool    mIsToRecyle;
    bool    mIsOverWrite;
    int     mRet;
    QString               mConsumerKey;
    QString               mConsumerSecret;
    QString               mTmpTokenSecret;
    QString               mTmpToken;
    QString               mDataPath;
    QString               mCreateFolderPath;
    QString               mDelFilePath;
    QString               mFromPath;
    QString               mToPath;
    QString               mUploadNode;
    struAuToken           mAuTokenInfo;
    struUsrInfo           mUsrInfo;
    QByteArray            mJsonBuf;

private:
    void    addTknNonceTimes(QString &paraStr,QString &consKeyStr);
    int     openFile(QByteArray &buf,const QString &filePath);
    QString buildReqTknUrl(QString &consKeyStr, QString &consKeySecretStr);
    QString getReqTknSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr);

    QString buildAcesTknUrl(QString &consKeyStr,QString &consKeySecretStr,\
                              QString &tmpTknStr,QString &tmpTknSercetStr);
    QString getAcesTknSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                QString &tmpTknStr,QString &tmpTknSercetStr);

    QString buildUsrInfoUrl(QString &consKeyStr,QString &consKeySecretStr,\
                            QString &oauTknStr,QString &oauTknSercetStr);
    QString getUsrInfoSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                QString &oauTknStr,QString &oauTknSercetStr);

    QString buildMetaDataUrl(QString &consKeyStr,QString &consKeySecretStr,\
                             QString &oauTknStr,QString &oauTknSercetStr,\
                             bool &isAppPath,QString &dataPath);
    QString getMetaDataSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                 QString &oauTknStr,QString &oauTknSercetStr,\
                                 QString &newGetMetaUrl);

    QString buildCreateFolderUrl(QString &consKeyStr,QString &consKeySecretStr,\
                                 QString &oauTknStr,QString &oauTknSercetStr,\
                                 bool &isAppPath,QString &folderName);
    QString getCreateFolderSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                     QString &oauTknStr,QString &oauTknSercetStr,\
                                     bool &isAppPath,QString &folderName);

    QString buildDelFileUrl(QString &consKeyStr,QString &consKeySecretStr,\
                            QString &oauTknStr,QString &oauTknSercetStr,\
                            bool &isAppPath,QString &fileName,bool &toRecyle);
    QString getDelFileSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                QString &oauTknStr,QString &oauTknSercetStr,\
                                bool &isAppPath,QString &fileName,bool &toRecyle);

    QString buildMoveFileUrl(QString &consKeyStr,QString &consKeySecretStr,\
                             QString &oauTknStr,QString &oauTknSercetStr,\
                             bool &isAppPath,QString &fromPath,QString &toPath);
    QString getMoveFileSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                 QString &oauTknStr,QString &oauTknSercetStr,\
                                 bool &isAppPath,QString &fromPath,QString &toPath);

    QString buildCopyFileUrl(QString &consKeyStr,QString &consKeySecretStr,\
                             QString &oauTknStr,QString &oauTknSercetStr,\
                             bool &isAppPath,QString &fromPath,QString &toPath);
    QString getCopyFileSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                 QString &oauTknStr,QString &oauTknSercetStr,\
                                 bool &isAppPath,QString &fromPath,QString &toPath);

    QString buildUploadLocateUrl(QString &consKeyStr,QString &consKeySecretStr,\
                                 QString &oauTknStr,QString &oauTknSercetStr);
    QString getUploadLocateSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                     QString &oauTknStr,QString &oauTknSercetStr);

    QString buildUploadFileUrl(QString &consKeyStr,QString &consKeySecretStr,\
                               QString &oauTknStr,QString &oauTknSercetStr,\
                               const bool &isOverWrite, const bool &isAppPath,\
                               const QString &toPath,QString &preStr);
    QString getUploadFileSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                   QString &oauTknStr,QString &oauTknSercetStr,\
                                   const bool &isOverWrite,const bool &isAppPath,\
                                   const QString &toPath,QString &fullUrl);
    void    buildMultiPart(QByteArray &data,QString &fileName);

    QString buildDownFileUrl(QString &consKeyStr,QString &consKeySecretStr,\
                             QString &oauTknStr,QString &oauTknSercetStr,\
                             bool &isAppPath,QString &fromPath);
    QString getDownFileSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                 QString &oauTknStr,QString &oauTknSercetStr,\
                                 bool &isAppPath,QString &fromPath);

    QString buildShareFileUrl(QString &consKeyStr,QString &consKeySecretStr,\
                              QString &oauTknStr,QString &oauTknSercetStr,\
                              bool &isAppPath,QString &dataPath);
    QString getShareFileSignature(QString &paraStr,QString &consKeyStr,QString &consKeySecretStr,\
                                  QString &oauTknStr,QString &oauTknSercetStr,\
                                  QString &newShareFileUrl);
    QUrl                  inputUrl;
    QNetworkRequest       request;
    QNetworkRequest       uploadRequest;
    QNetworkReply         *mReqTknReply;
    QNetworkReply         *mAcesTknReply;
    QNetworkReply         *mUsrInfoReply;
    QNetworkReply         *mMetaDataReply;
    QNetworkReply         *mCreateFolderReply;
    QNetworkReply         *mDelFileReply;
    QNetworkReply         *mMvFileReply;
    QNetworkReply         *mCpFileReply;
    QNetworkReply         *mUploadLocateReply;
    QNetworkReply         *mUploadFileReply;
    QNetworkReply         *mDownloadFileReply;
    QNetworkReply         *mDwnFileRealReply;
    QNetworkReply         *mShareFileReply;
    QNetworkAccessManager *manager;
    QEventLoop            *eLoop;

    QByteArray            mDwnFileBuf;
    QFile                 *dwnFile;

signals:
    void helloworld();
public slots:
    void reqTknReplyFinished();
    void acesTknReplyFinished();
    void usrInfoReplyFinished();
    void metaDataReadReady();
    void metaDataReplyFinished();
    void createFolderReplyFinished();
    void delFileReplyFinished();
    void moveFileReplyFinished();
    void copyFileReplyFinished();
    void getUploadLocateFinished();
    void uploadFileReplyFinished();
    void downLoadFileReplyFinished();
    void dwnFileRealReplyFinished();
    void shareFileReplyFinished();
};

#endif // KPSDK_H
