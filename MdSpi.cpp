#include "MdSpi.h"
#include <iostream>
using namespace std;

#pragma warning(disable : 4996)

//char *ppInstrumentID[] = { "a1701"};
//int iInstrumentID = 1; //行情订阅数量

char *ppInstrumentID[] = { "a1701", "a1703", "a1705", "a1707", "a1709", "a1711", "a1801", "a1803", "a1805", "b1701", "b1703", "b1705", "b1707", "b1709", "b1711", "bb1701", "bb1702", "bb1703", "bb1704", "bb1705", "bb1706", "bb1707", "bb1708", "bb1709", "bb1710", "bb1711", "bb1712", "c1701", "c1703", "c1705", "c1707", "c1709", "c1711", "cs1701", "cs1703", "cs1705", "cs1707", "cs1709", "cs1711", "fb1701", "fb1702", "fb1703", "fb1704", "fb1705", "fb1706", "fb1707", "fb1708", "fb1709", "fb1710", "fb1711", "fb1712", "i1701", "i1702", "i1703", "i1704", "i1705", "i1706", "i1707", "i1708", "i1709", "i1710", "i1711", "i1712", "j1701", "j1702", "j1703", "j1704", "j1705", "j1706", "j1707", "j1708", "j1709", "j1710", "j1711", "j1712", "jd1701", "jd1702", "jd1703", "jd1704", "jd1705", "jd1706", "jd1707", "jd1708", "jd1709", "jd1710", "jd1711", "jd1712", "jm1701", "jm1702", "jm1703", "jm1704", "jm1705", "jm1706", "jm1707", "jm1708", "jm1709", "jm1710", "jm1711", "jm1712", "l1701", "l1702", "l1703", "l1704", "l1705", "l1706", "l1707", "l1708", "l1709", "l1710", "l1711", "l1712", "m1701", "m1703", "m1705", "m1707", "m1708", "m1709", "m1711", "m1712", "p1701", "p1702", "p1703", "p1704", "p1705", "p1706", "p1707", "p1708", "p1709", "p1710", "p1711", "p1712", "pp1701", "pp1702", "pp1703", "pp1704", "pp1705", "pp1706", "pp1707", "pp1708", "pp1709", "pp1710", "pp1711", "pp1712", "v1701", "v1702", "v1703", "v1704", "v1705", "v1706", "v1707", "v1708", "v1709", "v1710", "v1711", "v1712", "y1701", "y1703", "y1705", "y1707", "y1708", "y1709", "y1711", "y1712", "ag1701", "ag1702", "ag1703", "ag1704", "ag1705", "ag1706", "ag1707", "ag1708", "ag1709", "ag1710", "ag1711", "ag1712", "al1701", "al1702", "al1703", "al1704", "al1705", "al1706", "al1707", "al1708", "al1709", "al1710", "al1711", "al1712", "au1701", "au1702", "au1703", "au1704", "au1706", "au1708", "au1710", "au1712", "bu1701", "bu1702", "bu1703", "bu1704", "bu1705", "bu1706", "bu1709", "bu1712", "bu1803", "bu1806", "bu1809", "bu1812", "cu1701", "cu1702", "cu1703", "cu1704", "cu1705", "cu1706", "cu1707", "cu1708", "cu1709", "cu1710", "cu1711", "cu1712", "fu1702", "fu1703", "fu1704", "fu1705", "fu1706", "fu1707", "fu1708", "fu1709", "fu1710", "fu1711", "fu1712", "hc1701", "hc1702", "hc1703", "hc1704", "hc1705", "hc1706", "hc1707", "hc1708", "hc1709", "hc1710", "hc1711", "hc1712", "ni1701", "ni1702", "ni1703", "ni1704", "ni1705", "ni1706", "ni1707", "ni1708", "ni1709", "ni1710", "ni1711", "ni1712", "pb1701", "pb1702", "pb1703", "pb1704", "pb1705", "pb1706", "pb1707", "pb1708", "pb1709", "pb1710", "pb1711", "pb1712", "rb1701", "rb1702", "rb1703", "rb1704", "rb1705", "rb1706", "rb1707", "rb1708", "rb1709", "rb1710", "rb1711", "rb1712", "ru1701", "ru1703", "ru1704", "ru1705", "ru1706", "ru1707", "ru1708", "ru1709", "ru1710", "ru1711", "sn1701", "sn1702", "sn1703", "sn1704", "sn1705", "sn1706", "sn1707", "sn1708", "sn1709", "sn1710", "sn1711", "sn1712", "wr1701", "wr1702", "wr1703", "wr1704", "wr1705", "wr1706", "wr1707", "wr1708", "wr1709", "wr1710", "wr1711", "wr1712", "zn1701", "zn1702", "zn1703", "zn1704", "zn1705", "zn1706", "zn1707", "zn1708", "zn1709", "zn1710", "zn1711", "zn1712", "IC00C1", "IC00C2", "IC00C3", "IC00C4", "IC1612", "IC1701", "IC1703", "IC1706", "IF00C1", "IF00C2", "IF00C3", "IF00C4", "IF1612", "IF1701", "IF1703", "IF1706", "IH00C1", "IH00C2", "IH00C3", "IH00C4", "IH1612", "IH1701", "IH1703", "IH1706", "T00C1", "T00C2", "T00C3", "T1703", "T1706", "T1709", "TF00C1", "TF00C2", "TF00C3", "TF1703", "TF1706", "TF1709", "CF701", "CF703", "CF705", "CF707", "CF709", "CF711", "FG701", "FG702", "FG703", "FG704", "FG705", "FG706", "FG707", "FG708", "FG709", "FG710", "FG711", "FG712", "JR701", "JR703", "JR705", "JR707", "JR709", "JR711", "LR701", "LR703", "LR705", "LR707", "LR709", "LR711", "MA701", "MA702", "MA703", "MA704", "MA705", "MA706", "MA707", "MA708", "MA709", "MA710", "MA711", "MA712", "OI701", "OI703", "OI705", "OI707", "OI709", "OI711", "PM701", "PM703", "PM705", "PM707", "PM709", "PM711", "RI701", "RI703", "RI705", "RI707", "RI709", "RI711", "RM701", "RM703", "RM705", "RM707", "RM708", "RM709", "RM711", "RS707", "RS708", "RS709", "RS711", "SF701", "SF702", "SF703", "SF704", "SF705", "SF706", "SF707", "SF708", "SF709", "SF710", "SF711", "SF712", "SM701", "SM702", "SM703", "SM704", "SM705", "SM706", "SM707", "SM708", "SM709", "SM710", "SM711", "SM712", "SR701", "SR703", "SR705", "SR707", "SR709", "SR711", "SR801", "SR803", "SR805", "TA701", "TA702", "TA703", "TA704", "TA705", "TA706", "TA707", "TA708", "TA709", "TA710", "TA711", "TA712", "WH701", "WH703", "WH705", "WH707", "WH709", "WH711", "ZC701", "ZC702", "ZC703", "ZC704", "ZC705", "ZC706", "ZC707", "ZC708", "ZC709", "ZC710", "ZC711", "ZC712" };
//char *ppInstrumentID[] = { "cu1702","zn1702","al1701","au1706","CF1705","SR1705","pb1702","ag1706","rb1705","ru1705","bu1705","hc1705","cl1705","jd1705","j1705","y1705","jm1705","IF1701","TF1703","WH1701"}; //行情订阅列表
int iInstrumentID = 494; //行情订阅数量

int iRequestID = 0;

MdSpi::MdSpi(QObject *parent)
	: QObject(parent)
{

}

MdSpi::~MdSpi()
{

}

void MdSpi::Init()
{
	//初始化UserApi
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi
	pUserApi->RegisterSpi(this);						// 注册事件类
	pUserApi->RegisterFront(hq.FRONT_ADDR);					// connect
	pUserApi->Init();
}

void MdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo,
	int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << __FUNCTION__ << endl;
	IsErrorRspInfo(pRspInfo);
}

void MdSpi::OnFrontDisconnected(int nReason)
{
	cerr << "--->>> " << __FUNCTION__ << endl;
	cerr << "--->>> Reason = " << nReason << endl;
}

void MdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cerr << "--->>> " << __FUNCTION__ << endl;
	cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

void MdSpi::OnFrontConnected()
{
	cerr << "--->>> " << __FUNCTION__ << endl;
	///用户登录请求
	ReqUserLogin();
}

void MdSpi::ReqUserLogin()
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, hq.BROCKER_ID);
	strcpy(req.UserID, "");
	strcpy(req.Password, "");
	int iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
	cerr << "--->>> 发送用户登录请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void MdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		///获取当前交易日
		cerr << "--->>> 获取当前交易日 = " << pUserApi->GetTradingDay() << endl;
		// 请求订阅行情
		SubscribeMarketData();
	}
}

void MdSpi::SubscribeMarketData()
{
	int iResult = pUserApi->SubscribeMarketData(ppInstrumentID, iInstrumentID);
	cerr << "--->>> 发送行情订阅请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void MdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << __FUNCTION__ << endl;
}

void MdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << __FUNCTION__ << endl;
}

void MdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	///交易日 TradingDay;
	///合约代码 InstrumentID;
	///交易所代码 ExchangeID;
	///合约在交易所的代码 ExchangeInstID;
	///最新价 LastPrice;
	///上次结算价 PreSettlementPrice;
	///昨收盘 PreClosePrice;
	///昨持仓量 PreOpenInterest;
	///今开盘 OpenPrice;
	///最高价 HighestPrice;
	///最低价 LowestPrice;
	///数量 Volume;
	///成交金额 Turnover;
	///持仓量 OpenInterest;
	///今收盘 ClosePrice;
	///本次结算价 SettlementPrice;
	///涨停板价 UpperLimitPrice;
	///跌停板价 LowerLimitPrice;
	///昨虚实度 PreDelta;
	///今虚实度 CurrDelta;
	///最后修改时间 UpdateTime;
	///最后修改毫秒 UpdateMillisec;
	///申买价一 BidPrice1;
	///申买量一 BidVolume1;
	///申卖价一 AskPrice1;
	///申卖量一 AskVolume1;
	///申买价二 BidPrice2;
	///申买量二 BidVolume2;
	///申卖价二 AskPrice2;
	///申卖量二 AskVolume2;
	///申买价三 BidPrice3;
	///申买量三 BidVolume3;
	///申卖价三 AskPrice3;
	///申卖量三 AskVolume3;
	///申买价四 BidPrice4;
	///申买量四 BidVolume4;
	///申卖价四 AskPrice4;
	///申卖量四 AskVolume4;
	///申买价五 BidPrice5;
	///申买量五 BidVolume5;
	///申卖价五 AskPrice5;
	///申卖量五 AskVolume5;
	///当日均价 AveragePrice;
	///业务日期 ActionDay;
	QString instrument_id = pDepthMarketData->InstrumentID;
	QString update_time = pDepthMarketData->UpdateTime;
	QString last_price = QString::number(pDepthMarketData->LastPrice);
	QString bid_price1 = QString::number(pDepthMarketData->BidPrice1);
	QString bid_volume1 = QString::number(pDepthMarketData->BidVolume1);
	//QString bid_volume1 = pDepthMarketData->BidVolume1;
	QString ask_price1 = QString::number(pDepthMarketData->AskPrice1);
	QString ask_volume1 = QString::number(pDepthMarketData->AskVolume1);
	//QString ask_volume1 = pDepthMarketData->AskVolume1;
	QString increase = QString::number(((pDepthMarketData->LastPrice - pDepthMarketData->PreClosePrice)*100/pDepthMarketData->PreClosePrice),'f',2);
	QString volume = QString::number(pDepthMarketData->Volume);
	//QString volume = pDepthMarketData->Volume;
	QString upper_limit_price = QString::number(pDepthMarketData->UpperLimitPrice);
	QString lower_limit_price = QString::number(pDepthMarketData->LowerLimitPrice);

	////////////
	QString trading_day = pDepthMarketData->TradingDay;
	QString exchange_id = pDepthMarketData->ExchangeID;
	QString exchange_inst_id = pDepthMarketData->ExchangeInstID;
	QString pre_settlement_price = QString::number(pDepthMarketData->PreSettlementPrice);
	QString pre_close_price = QString::number(pDepthMarketData->PreClosePrice);
	QString pre_open_interest = QString::number(pDepthMarketData->PreOpenInterest);
	QString open_price = QString::number(pDepthMarketData->OpenPrice);
	QString highest_price = QString::number(pDepthMarketData->HighestPrice);
	QString lowest_price = QString::number(pDepthMarketData->LowestPrice);
	QString turnover = QString::number(pDepthMarketData->Turnover);
	QString openinstrest = QString::number(pDepthMarketData->OpenInterest);
	QString close_price = QString::number(pDepthMarketData->ClosePrice);
	QString settlement_price = QString::number(pDepthMarketData->SettlementPrice);
	QString pre_delta = QString::number(pDepthMarketData->PreDelta);
	QString curr_delta = QString::number(pDepthMarketData->CurrDelta);
	QString update_millisec = QString::number(pDepthMarketData->UpdateMillisec);
	QString bid_price2 = QString::number(pDepthMarketData->BidPrice2);
	QString bid_volume2 = QString::number(pDepthMarketData->BidVolume2);
	//QString bid_volume2 = pDepthMarketData->BidVolume2;
	QString ask_price2 = QString::number(pDepthMarketData->AskPrice2);
	QString ask_volume2 = QString::number(pDepthMarketData->AskVolume2);
	//QString ask_volume2 = pDepthMarketData->AskVolume2;
	QString bid_price3 = QString::number(pDepthMarketData->BidPrice3);
	QString bid_volume3 = QString::number(pDepthMarketData->BidVolume3);
	//QString bid_volume3 = pDepthMarketData->BidVolume3;
	QString ask_price3 = QString::number(pDepthMarketData->AskPrice3);
	QString ask_volume3 = QString::number(pDepthMarketData->AskVolume3);
	//QString ask_volume3 = pDepthMarketData->AskVolume3;
	QString bid_price4 = QString::number(pDepthMarketData->BidPrice4);
	QString bid_volume4 = QString::number(pDepthMarketData->BidVolume4);
	//QString bid_volume4 = pDepthMarketData->BidVolume4;
	QString ask_price4 = QString::number(pDepthMarketData->AskPrice4);
	QString ask_volume4 = QString::number(pDepthMarketData->AskVolume4);
	//QString ask_volume4 = pDepthMarketData->AskVolume4;
	QString bid_price5 = QString::number(pDepthMarketData->BidPrice5);
	QString bid_volume5 = QString::number(pDepthMarketData->BidVolume5);
	//QString bid_volume5 = pDepthMarketData->BidVolume5;
	QString ask_price5 = QString::number(pDepthMarketData->AskPrice5);
	QString ask_volume5 = QString::number(pDepthMarketData->AskVolume5);
	//QString ask_volume5 = pDepthMarketData->AskVolume5;
	QString average_price = QString::number(pDepthMarketData->AveragePrice);
	QString action_day = pDepthMarketData->ActionDay;

	QString hq_tick = instrument_id + "," + update_time + "," + last_price + "," + bid_price1 + "," + bid_volume1 + ",";
	hq_tick = hq_tick + ask_price1 + "," + ask_volume1 + "," + increase + "," + volume + ",";
	hq_tick = hq_tick + upper_limit_price + "," + lower_limit_price + ",";
	//////////////
	hq_tick = hq_tick + trading_day + "," + exchange_id + "," + exchange_inst_id + "," + pre_settlement_price + ",";
	hq_tick = hq_tick + pre_close_price + "," + pre_open_interest + "," + open_price + "," + highest_price + ",";
	hq_tick = hq_tick + lowest_price + "," + turnover + "," + openinstrest + "," + close_price + ",";
	hq_tick = hq_tick + settlement_price + "," + pre_delta + "," + curr_delta + "," + update_millisec + ",";
	hq_tick = hq_tick + bid_price2 + "," + bid_volume2 + "," + ask_price2 + "," + ask_volume2 + ",";
	hq_tick = hq_tick + bid_price3 + "," + bid_volume3 + "," + ask_price3 + "," + ask_volume3 + ",";
	hq_tick = hq_tick + bid_price4 + "," + bid_volume4 + "," + ask_price4 + "," + ask_volume4 + ",";
	hq_tick = hq_tick + bid_price5 + "," + bid_volume5 + "," + ask_price5 + "," + ask_volume5 + ",";
	hq_tick = hq_tick + average_price + "," + action_day;

	emit SendHqToDB(hq_tick);
	//emit SendHqToDB2(pDepthMarketData);
}

bool MdSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
		cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	return bResult;
}