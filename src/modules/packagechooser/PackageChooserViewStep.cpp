/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2019, Adriaan de Groot <groot@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#include "PackageChooserViewStep.h"

#include "PackageChooserPage.h"

#include "GlobalStorage.h"
#include "JobQueue.h"

#include "utils/CalamaresUtilsSystem.h"
#include "utils/Logger.h"
#include "utils/Variant.h"

#include <QDesktopServices>
#include <QVariantMap>

CALAMARES_PLUGIN_FACTORY_DEFINITION( PackageChooserViewStepFactory, registerPlugin< PackageChooserViewStep >(); )

PackageChooserViewStep::PackageChooserViewStep( QObject* parent )
    : Calamares::ViewStep( parent )
    , m_widget( nullptr )
{
    emit nextStatusChanged( false );
}


PackageChooserViewStep::~PackageChooserViewStep()
{
    if ( m_widget && m_widget->parent() == nullptr )
    {
        m_widget->deleteLater();
    }
}


QString
PackageChooserViewStep::prettyName() const
{
    return tr( "Packages" );
}


QWidget*
PackageChooserViewStep::widget()
{
    if ( !m_widget )
    {
        m_widget = new PackageChooserPage( nullptr );
    }
    return m_widget;
}


bool
PackageChooserViewStep::isNextEnabled() const
{
    return true;
}


bool
PackageChooserViewStep::isBackEnabled() const
{
    return true;
}


bool
PackageChooserViewStep::isAtBeginning() const
{
    return true;
}


bool
PackageChooserViewStep::isAtEnd() const
{
    return true;
}


void
PackageChooserViewStep::onLeave()
{
}

Calamares::JobList
PackageChooserViewStep::jobs() const
{
    Calamares::JobList l;
    return l;
}

void
PackageChooserViewStep::setConfigurationMap( const QVariantMap& configurationMap )
{
}
