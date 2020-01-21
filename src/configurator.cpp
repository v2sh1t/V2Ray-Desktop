#include "configurator.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>

#include "constants.h"

QJsonObject Configurator::DEFAULT_APP_CONFIG = {
  {"autoStart", DEFAULT_AUTO_START},
  {"hideWindow", DEFAULT_HIDE_WINDOW},
  {"autoUpdate", DEFAULT_AUTO_UPDATE},
  {"enableUdp", DEFAULT_ENABLE_UDP},
  {"serverProtocol", DEFAULT_SERVER_PROTOCOL},
  {"serverIp", DEFAULT_SERVER_IP},
  {"serverPort", DEFAULT_SERVER_PORT},
  {"pacPort", DEFAULT_PAC_PORT},
  {"mux", DEFAULT_MUX},
  {"dns", DEFAULT_DNS_SERVER},
  {"proxyMode", DEFAULT_PROXY_MODE},
  {"gfwListUrl", DEFAULT_GFW_LIST_URL},
  {"gfwListLastUpdated", "Never"},
  {"v2rayCoreVersion", DEFAULT_V2RAY_CORE_VERSION},
};

Configurator::Configurator() {}

QJsonObject Configurator::getAppConfig() {
  QJsonObject config = DEFAULT_APP_CONFIG;
  QFile appCfgFile(APP_CFG_FILE_PATH);
  if (appCfgFile.exists() &&
      appCfgFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QJsonDocument configDoc = QJsonDocument::fromJson(appCfgFile.readAll());
      config = configDoc.object();
      if (config.empty()) {
        qWarning() << "Failed to parse the app config.";
        config = DEFAULT_APP_CONFIG;
      }
  }
  return config;
}

void Configurator::setAppConfig(QJsonObject config) {
  // Load current configuration
  QJsonObject _config = getAppConfig();
  // Overwrite new values to current configuration
  for (auto itr = config.begin(); itr != config.end(); ++itr) {
    QString configName   = itr.key();
    QVariant configValue = itr.value().toVariant();
    switch (configValue.type()) {
      case QVariant::Bool: _config[configName] = configValue.toBool(); break;
      case QVariant::String:
        _config[configName] = configValue.toString();
        break;
      default:
        qWarning() << "Ignore unknown config item [Name=" << configName
                   << ", Type=" << configValue.type() << "]";
        break;
    }
  }
  // Save config to file
  QFile configFile(APP_CFG_FILE_PATH);
  configFile.open(QFile::WriteOnly);
  configFile.write(QJsonDocument(_config).toJson());
}

QJsonObject Configurator::getV2RayConfig() {
  QJsonObject appConfig   = getAppConfig();
  QJsonObject v2RayConfig{
    {"log",
     QJsonObject{{"loglevel", "info"}, {"error", V2RAY_CORE_LOG_FILE_PATH}}},
    {"inbounds",
     QJsonArray{QJsonObject{
       {"listen", appConfig["serverIp"].toString()},
       {"protocol", appConfig["serverProtocol"].toString().toLower()},
       {"port", appConfig["serverPort"].toString()},
       {"settings", QJsonObject{{"udp", appConfig["enableUdp"].toBool()}}},
     }}},
    {"outbounds", getAutoConnectServers()},
    {"dns", QJsonObject{{"servers",
                         getPrettyDnsServers(appConfig["dns"].toString())}}},
    {"rules", QJsonObject{
                {"strategy", "rules"},
                {"settings", QJsonObject {
                  {"domainStrategy", "IPIfNonMatch"},
                  {"rules", getRules()}
                }}
              }}};
  return v2RayConfig;
}

QJsonArray Configurator::getPrettyDnsServers(QString dnsString) {
  QJsonArray dnsServers;
  QStringList _dnsServers = dnsString.split(',');
  for (QString ds : _dnsServers) {
    dnsServers.append(ds.trimmed());
  }
  return dnsServers;
}

QJsonArray Configurator::getServers() {
  QJsonObject appConfig = getAppConfig();
  QJsonArray servers = appConfig.contains("servers") ? appConfig["servers"].toArray() : QJsonArray();
  for (auto itr = servers.begin(); itr != servers.end(); ++ itr) {

  }
  return servers;
}

QJsonArray Configurator::getAutoConnectServers() {
  QJsonArray servers = getServers();
  QJsonArray autoConnectServers;
  for (auto itr = servers.begin(); itr != servers.end(); ++ itr) {
    QJsonObject server = (*itr).toObject();
    if (server["autoConnect"].toBool()) {
      server.remove("autoConnect");
      autoConnectServers.append(server);
    }
  }
  autoConnectServers.append(
    QJsonObject{{"tag", "direct"}, {"protocol", "freedom"}});
  return autoConnectServers;
}

QJsonArray Configurator::getRules() {
  // Ref: https://v2ray.com/chapter_02/03_routing.html
  QJsonArray rules;
  return rules;
}