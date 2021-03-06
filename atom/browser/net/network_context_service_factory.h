// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_NET_NETWORK_CONTEXT_SERVICE_FACTORY_H_
#define ATOM_BROWSER_NET_NETWORK_CONTEXT_SERVICE_FACTORY_H_

#include "base/memory/singleton.h"
#include "components/keyed_service/content/browser_context_keyed_service_factory.h"

class KeyedService;

namespace contenet {
class BrowserContext;
}

namespace atom {

class NetworkContextService;

class NetworkContextServiceFactory : public BrowserContextKeyedServiceFactory {
 public:
  // Returns the NetworkContextService that supports NetworkContexts for
  // |browser_context|.
  static NetworkContextService* GetForContext(
      content::BrowserContext* browser_context);

  // Returns the NetworkContextServiceFactory singleton.
  static NetworkContextServiceFactory* GetInstance();

  NetworkContextServiceFactory(const NetworkContextServiceFactory&) = delete;
  NetworkContextServiceFactory& operator=(const NetworkContextServiceFactory&) =
      delete;

 private:
  friend struct base::DefaultSingletonTraits<NetworkContextServiceFactory>;

  NetworkContextServiceFactory();
  ~NetworkContextServiceFactory() override;

  // BrowserContextKeyedServiceFactory implementation:
  KeyedService* BuildServiceInstanceFor(
      content::BrowserContext* context) const override;
  content::BrowserContext* GetBrowserContextToUse(
      content::BrowserContext* context) const override;
};

}  // namespace atom

#endif  // ATOM_BROWSER_NET_NETWORK_CONTEXT_SERVICE_FACTORY_H_
