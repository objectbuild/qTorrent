#ifndef PEER_H
#define PEER_H

#include <QByteArray>
#include <QObject>

class Torrent;
class TorrentClient;

class Peer : public QObject {
	Q_OBJECT

	Torrent* m_torrent;
	QByteArray m_address;
	int m_port;
	TorrentClient* m_torrentClient;

	int m_bitfieldSize;
	bool* m_bitfield;
	/* Handshaking info */
	QByteArray m_protocol;
	QByteArray m_reserved;
	QByteArray m_infoHash;
	QByteArray m_peerId;
public:
	Peer(Torrent* torrent, const QByteArray& address, int port);
	~Peer();
	Torrent* torrent();
	QByteArray& address();
	int port();
	TorrentClient* torrentClient();
	void startConnection();
	int& bitfieldSize();
	bool*& bitfield();
	QByteArray& protocol();
	QByteArray& reserved();
	QByteArray& infoHash();
	QByteArray& peerId();
};

#endif // PEER_H
