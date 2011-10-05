#ifndef __XPO_QUERY_BUILDER_H
#define __XPO_QUERY_BUILDER_H

// ---------------------------------------------------------------------------|
// Test Harness includes
// ---------------------------------------------------------------------------|
#include "test/support/msg-util/NCMessageBuilder.h"
#include "test/support/db-models/device-test-db.h"

// ---------------------------------------------------------------------------|
// Standard includes
// ---------------------------------------------------------------------------|
#include <cstdint>
#include <string>

// ---------------------------------------------------------------------------|
namespace YumaTest
{

/**
 * Utility lass for build queries aginst teh device test XPO
 * container.
 */
class XPOQueryBuilder : public NCMessageBuilder
{
public:
    /** 
     * Constructor.
     *
     * \param moduleNs the namespace of the module defining the XPO
     * container.
     */
    explicit XPOQueryBuilder( const std::string& moduleNS );

    /** Destructor */
    virtual ~XPOQueryBuilder();

    /**
     * Add the profile node path and the xpo module to the XML query.
     *
     * \param profileId the id of the profile
     * \param queryText the query to add the path to.
     * \retrun the formatted xml query,
     */
    std::string addProfileNodePath( 
        const uint16_t profileId,
        const std::string& queryText ) const;

    /** 
     * Add the path to the resource node (profile.stream.resource)
     *
     * \param profileId the of the owning profile.
     * \param streamId the of the stream to create. 
     * \param resourceId the id of the connection node to create.
     * \param queryText the resource query to add the path to.
     * \return XML formatted query
     */
    std::string addProfileStreamNodePath( 
        const uint16_t profileId,
        const uint16_t streamId,
        const std::string& queryText ) const;

    /** 
     * Add the path to the stream connection (streamConnection)
     *
     * \param streamId the of the stream to create. 
     * \param queryText the resource query to add the path to.
     * \return XML formatted query
     */
    std::string addStreamConnectionPath( 
        uint16_t connectionId,
        const std::string& queryText ) const;

    /** 
     * Add the path to the resource node (profile.stream.resource).
     *
     * \param profileId the id of the owning profile.
     * \param streamId the id of the owning stream.
     * \param resourceId the id of the resource node.
     * \param queryText the resource query to add the path to.
     * \return XML formatted query
     */
    std::string addResourceNodePath( 
        const uint16_t profileId,
        const uint16_t streamId,
        const uint16_t resourceId,
        const std::string& queryText ) const;

    /** 
     * Add the path to the VR connection node
     * (profile.stream.connection).
     *
     * \param profileId the id of the owning profile.
     * \param streamId the id of the owning stream.
     * \param connectionId the id of the connection node.
     * \param queryText the resource query to add the path to.
     * \return XML formatted query
     */
    std::string addVRConnectionNodePath( 
        const uint16_t profileId,
        const uint16_t streamId,
        const uint16_t connectionId,
        const std::string& queryText ) const;

    /**
     * Generate a query on the basic XPO container.
     *
     * \param op the operation to perform.
     * \return XML formatted query
     */
    std::string genXPOQuery( const std::string& op ) const;

    /**
     * Generate a query to set the active profile id.
     *
     * \param profileId the id of the new active profile
     * \param op the operation to perform.
     * \return XML formatted query
     */
    std::string genSetActiveProfileIdQuery( uint16_t profileId,
           const std::string& op ) const;

    /**
     * Generate a query for a specific profile.
     *
     * \param profileId the id of the profile
     * \param op the operation to perform.
     * \return XML formatted query
     */
    std::string genProfileQuery( uint16_t profileId, const std::string& op ) const;

    /**
     * Generate a query for a specific stream item in a profile.
     *
     * \param profileId the id of the profile
     * \param streamId the id of the stream
     * \param op the operation to perform.
     * \return XML formatted query
     */
    std::string genProfileChildQuery( uint16_t profileId, 
                                      uint16_t streamId, 
                                      const std::string& op ) const;
    /** 
     * Generate a query for a child node of profile.
     *
     * \param profileId the of the owning profile.
     * \param streamId the of the stream to create. 
     * \param nodeName the name of the child node to create. 
     * \param nodeId the id of the child to create. 
     * \param resourceNodeId the id of the resource node to create.
     * \return XML formatted query
     */
    std::string genProfileChildQuery( const uint16_t profileId,
                                      const uint16_t streamId,
                                      const std::string&  nodeName,
                                      const uint16_t nodeId,
                                      const std::string& op ) const;
    
    /**
     * Configure a connection item.
     * This function generates the complete configuration for a
     * ConnectionItem, items are configured depending on whether or
     * not they have been set in the supplied ConnectionItemConfig.
     *
     * \param config the configuration to generate
     * \param op the operation being performed
     * \return XML representation of the data being configured.
     */
     std::string configureVRConnectionItem( 
        const YumaTest::ConnectionItemConfig& config,
        const std::string& op ) const;

   /**
     * Configure a Virtual resource item.
     * This function generates the complete configuration for a
     * ResourceNode, items are configured depending on whether or
     * not they have been set in the supplied ResourceNodeConfig.
     *
     * \param config the configuration to generate
     * \param op the operation being performed
     * \return XML representation of the data being configured.
     */
     std::string configureVResourceNode( 
         const YumaTest::ResourceNodeConfig& config, 
         const std::string& op ) const;

    /**
     * Generate a query for a specific stream.
     *
     * \param streamId the id of the stream
     * \param op the operation to perform.
     * \return XML formatted query
     */
     std::string genStreamConnectionQuery( 
           uint16_t streamId,
           const std::string& op ) const;

     /**
      *
      * Generate a query for a specific stream in a profile.
      *
      * \param profileId the id of the stream
      * \param streamId the id of the stream
      * \param op the operation to perform.
      * \return XML formatted query
      */
     std::string genProfileStreamItemQuery( uint16_t profileId,
                                            uint16_t streamId,
                                            const std::string& op ) const;
private:
     const std::string moduleNs_; ///< the module's namespace
};

} // namespace YumaTest

#endif // __XPO_QUERY_BUILDER_H